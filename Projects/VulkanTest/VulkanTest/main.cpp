#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

const int WIDTH = 800;
const int HEIGHT = 600;

class HelloTriangleApplication {
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	GLFWwindow* window;

	void initWindow() {

		//initializes the GLFW library
		glfwInit();

		//Because GLFW was originally designed to create an OpenGL context, 
		//we need to tell it to not create an OpenGL context with a subsequent call
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		
		//Disable resizing for now, more code to handle
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		//Creating the actual window
		//Optionally specify monitor to open the window on
		//last relevant to OpenGL only
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

	}

	void initVulkan() {

	}

	void mainLoop() {
		//keep the application running until either an error occurs or the window is closed
		while (!glfwWindowShouldClose(window)) {
			//checks for events like pressing the X button until the window has been closed by the user
			glfwPollEvents();
		}
	}

	void cleanup() {
		//destroying it 
		glfwDestroyWindow(window);
		//terminate glfw itself
		glfwTerminate();
	}
};

int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}