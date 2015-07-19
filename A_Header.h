// Подключаем библиотеки
#include <irrlicht.h>
#include <iostream>
#include <fstream>





// Объявляем пространства имен
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;





// Глобальные объекты движка
IrrlichtDevice *device;
IVideoDriver* driver;
ISceneManager* smgr;
IGUIEnvironment* gui;
IMetaTriangleSelector* meta;
SIrrlichtCreationParameters params;




// Переменные для фиксации FPS
s32 framelimit = 35, //FPS
now = 0;
u32 sceneStartTime = 0,
sceneSkipTime = 1000 / framelimit;



