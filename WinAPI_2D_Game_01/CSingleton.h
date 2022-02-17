#pragma once
//singleton
#define SINGLE(type) static type* GetInst() {static type mgr; return &mgr;}

#define SINGLETON(CLASS)		\
private:						\
	CLASS();					\
	~Class();					\
	static CLASS* _instance;	\
public:							\
	static CLASS* getInst();	\
	{							\
		if(nullptr==_instance)	\
			_instance=new CLASS;\
		return_instance;		\
	}							\
	void release()				\
	{							\
		if(nullptr!=_instance)	\
		{						\
			delete _instance)	\
			_instance = nullptr;\
		}						\
	}							\
private:						\
	CLASS();					\
	~Class();					\
	static CLASS* _instance;	