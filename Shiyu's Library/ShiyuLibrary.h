//如果您需要调用此库的某些功能，请在您的代码中引用该库，并include此头文件，您可以尝试include特定的类，但因为类之间的互相调用，这通常会报错
//如果您需调用此库，请确保您使用的是C++17及以上的C++标准，并在预处理器中写上如下代码：
//NDEBUG;_CONSOLE;%(PreprocessorDefinitions) ; _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;_CRT_SECURE_NO_WARNINGS
#ifndef ShiyuLibrary_h
#define ShiyuLibrary_h
#include"SEncoding.h"
#include"SWebApi.h"
#include"SNumber.h"
#include"SArray.h"
#endif 


