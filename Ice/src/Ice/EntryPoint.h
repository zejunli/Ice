#pragma once

#ifdef ICE_PLATFORM_WINDOWS

extern Ice::Application* Ice::CreateApplication();

int main(int argc, char **argv) {
	Ice::Log::Init();
	ICE_CORE_WARN("WARNING!");
	int a = 10;
	ICE_INFO("THIS IS {0}", a);

	auto app = Ice::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
