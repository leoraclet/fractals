// C++
#include <array>
#include <iostream>
// Dear ImGui
#include "imgui/imgui-SFML.h"
#include "imgui/imgui-style.h"
#include "imgui/imgui.h"
// GLAD
#include "glad/glad.h"
// SFML
#include "SFML/Graphics.hpp"

// Quad vertices and indices
float vertices[] = {
    -1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f,
};
unsigned int indices[] = {
    0, 1, 2, 0, 3, 1,
};

int color = 1;                   // Color method
int type = 0;                    // Fractal type
int iterations = 100;            // Number of iterations
int mouse_x = 0;                 // Mouse X coordinates
int mouse_y = 0;                 // Mouse Y coordinates
bool mouse_clicked = false;      // Is mouse being clicked ?
std::array<float, 2> c = {0, 0}; // Value of C constant for Julia set

double d_zoom = 1.f / 256.f; // Zoom in the complex plane
double cx = 0.0;             // Position of the complex plane X-center on screen
double cy = 0.0;             // Position of the complex plane Y-center on screen
double w, h;                 // Width & Height of the rendered window

int main() {
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Fractals");

  h = (double)window.getSize().y;
  w = (double)window.getSize().x;

  // Initialize and load GLAD
  if (!gladLoadGL()) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // OpenGL viewport
  glViewport(0, 0, (int)w, (int)h);

  // Initialize Dear ImGui
  if (!ImGui::SFML::Init(window))
    return 1;

  setImGuiStyle();

  // Shader
  sf::Shader shader;

  // Load shader
  if (!shader.loadFromFile("../shared/fractal.vert",
                           "../shared/fractal.frag")) {
    std::cout << "Error loading shader" << std::endl;
  }

  // Shape
  unsigned int VAO, VBO, EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
               GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                        (void *)nullptr);

  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // Timer
  sf::Clock clock;

  // Window main loop
  while (window.isOpen()) {
    ImGui::SFML::Update(window, clock.restart());
    sf::Event event{};

    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(window, event);

      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      // Handle window resized event
      case sf::Event::Resized:
        glViewport(0, 0, (int)event.size.width, (int)event.size.height);
        break;

      // handle keyboard inputs
      case sf::Event::KeyReleased:
        switch (event.key.code) {
        case sf::Keyboard::Escape:
          window.close();
          break;
        default:
          break;
        }
        break;

      // Handle mouse motion
      case sf::Event::MouseMoved:
        if (mouse_clicked) {
          int delta_x = mouse_x - event.mouseMove.x;
          int delta_y = mouse_y - event.mouseMove.y;

          cx += delta_x * d_zoom;
          cy -= delta_y * d_zoom;
        }
        mouse_x = event.mouseMove.x;
        mouse_y = event.mouseMove.y;
        break;

      // Handle mouse scrolling
      case sf::Event::MouseWheelScrolled:
        if (event.mouseWheelScroll.delta > 0) {
          d_zoom *= 1.04;
        } else {
          d_zoom *= 0.96;
        }
        break;

      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
          mouse_clicked = true;
        }
        break;

      case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left) {
          mouse_clicked = false;
        }
        break;

      default:
        break;
      }
    }

    bool *p_open;
    // ImGui window - Menu
    ImGui::Begin("Simulation settings", p_open,
                 ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize);
    ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.9f);
    ImGui::Text("Fractal type :");
    ImGui::Combo(
        "##type", &type,
        "Mandelbrot\0Julia\0Burning Ship\0Tricorn\0Newton 1\0Newton 2\0\0");
    ImGui::NewLine();
    ImGui::Text("Maximum iterations :");
    ImGui::SliderInt("##i", &iterations, 100, 1000);
    ImGui::NewLine();
    if (type == 1) {
      ImGui::Text("The initial C value :");
      ImGui::SliderFloat2("##c", c.data(), -2.f, 2.f);
      ImGui::NewLine();
    }
    if (type < 4) {
      ImGui::Text("Color palette :");
      ImGui::Combo("##color", &color,
                   "Black and White\0Original\0Shades of "
                   "Grey\0Sky\0Fire\0Electrical\0Gold\0\0");
      ImGui::NewLine();
    }
    ImGui::Text("Zoom     : %0.20f", d_zoom);
    ImGui::Text("Center X : %0.20f", cx);
    ImGui::Text("Center Y : %0.20f", cy);
    ImGui::End();

    // OpenGL
    glEnable(GL_DEPTH_TEST);

    // Use shader
    sf::Shader::bind(&shader);

    // Transfers variables tp the shader
    float vec2[2];
    long double tmp;

    vec2[0] = float(cx);
    vec2[1] = float(cx - double(vec2[0]));

    shader.setUniform("cx0", vec2[0]);
    shader.setUniform("cx1", vec2[1]);

    vec2[0] = float(cy);
    vec2[1] = float(cy - double(vec2[0]));

    shader.setUniform("cy0", vec2[0]);
    shader.setUniform("cy1", vec2[1]);

    vec2[0] = float(d_zoom);
    vec2[1] = float(d_zoom - double(vec2[0]));

    shader.setUniform("z0", vec2[0]);
    shader.setUniform("z1", vec2[1]);

    tmp = -(double(w)) / 2.0 * d_zoom;
    vec2[0] = float(tmp);
    vec2[1] = float(tmp - double(vec2[0]));

    shader.setUniform("w0", vec2[0]);
    shader.setUniform("w1", vec2[1]);

    tmp = -(double(h)) / 2.0 * d_zoom;
    vec2[0] = float(tmp);
    vec2[1] = float(tmp - double(vec2[0]));

    shader.setUniform("h0", vec2[0]);
    shader.setUniform("h1", vec2[1]);

    shader.setUniform("cR", c[0]);
    shader.setUniform("cI", c[1]);

    shader.setUniform("fractal", type);
    shader.setUniform("iterations", iterations);
    shader.setUniform("color", color);

    // Load buffers and Draw pixels
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);

    // Render to window
    ImGui::SFML::Render(window);
    window.display();
  }

  // Cleanup buffer
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  // Shutdown Dear ImGui
  ImGui::SFML::Shutdown();

  return 0;
}