#pragma once
//singleton
#define SINGLETON(type)								\
													\
public:												\
	static type* GetInst()							\
	{												\
		static type _instance;						\
		return &_instance;							\
	}												\
private:											\
	type();											\
	~type();	
