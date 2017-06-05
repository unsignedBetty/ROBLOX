void exeLua(const char* script) {
	VMProtectBeginUltra("Lua Execution");
	lua_State *SphynxV2Env = lua_open();
	luaL_openlibs(SphynxV2Env);
	loadSphynxV2Registers(SphynxV2Env);

	//magik//
	if (luaL_dostring(SphynxV2Env, script) == 1) {
		const char* message = lua_tostring(SphynxV2Env, -1);
		getglobal(Roblox::lState, "warn");
		pustring(Roblox::lState, (message));
		pcll(Roblox::lState, 1, 0, 0);
	}

	else {
		getglobal(Roblox::lState, "print");
		pustring(Roblox::lState, "[SphynxV2]Executed.");
		pcll(Roblox::lState, 1, 0, 0);
	}
	//Done.//
	lua_close(SphynxV2Env);
	waittimeout = 30;
	stop(Roblox::lState, 0);
	VMProtectEnd();
}
