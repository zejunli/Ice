#pragma once

#ifdef ICE_PLATFORM_WINDOWS

extern Ice::Application* Ice::CreateApplication();

int main(int argc, char **argv) {
	auto app = Ice::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
