// Подгружаем библиотеки
#include "A_Header.h"
#include "A_Settings.h"
#include "A_Paths.h"
#include "C_KeyBoard.h"
#include "F_Function.h"




// Функция main() - основная функция
extern int main(int argc, char** argv)
{

 // Инициализация параметров
 params.AntiAlias= 32;
 params.Bits= 32;
 params.Fullscreen= 0;
 params.Stencilbuffer= 1;
 params.Vsync= 1;
 params.WindowSize.Height= sHeight;
 params.WindowSize.Width= sWidth;
 params.Stereobuffer= 0;
 params.ZBufferBits= 1;
 params.DriverType= EDT_OPENGL;
 params.EventReceiver= &myRec;


 // Создание игрового мира и девайса
 device = createDeviceEx(params); if (!device) return 600;
 driver = device->getVideoDriver();
 smgr = device->getSceneManager();
 meta= smgr->createMetaTriangleSelector();
 smgr->setShadowColor(SColor(150,0,0,0));



 // Создание камеры
 ICameraSceneNode* camera = smgr->addCameraSceneNode(0, vector3df(-50,30,0), vector3df(0,0,0));



 // Создание объектов

 IAnimatedMeshSceneNode* me= oLoadAnimMesh(0,50,0, RES_BALL);
 me->addChild(camera);

 IAnimatedMeshSceneNode* me2= oLoadAnimMesh(50,-10,0, RES_BALL2);


 IMeshSceneNode* world= oLoadStaticMesh(0,0,0, RES_MAP);
 setCollision(world, me);


 IMeshSceneNode* world2= oLoadStaticMesh(100,-100,0, RES_MAP2);
 setCollision(world2, me);
 setCollision(world2, me2);


 IAnimatedMeshSceneNode* cube= oLoadAnimMeshX(0,10,0, RES_CUBE);


 // Создание лапмы
 ILightSceneNode* lampa = smgr->addLightSceneNode(0,vector3df(0,100,0),SColorf(0.8f,0.8f,0.6f));
 lampa->setRadius(300);



 // Игровой цикл
 while (device->run())
 {
  now = device->getTimer()->getTime();
  if (now - sceneStartTime > sceneSkipTime)
  {
   sceneStartTime = device->getTimer()->getTime();
   ///////// GAME ////////////

   if (myRec.IsKeyPress(KEY_ESCAPE)) { return 1; }

   if (myRec.IsKeyPress(KEY_KEY_R)) { cube->setFrameLoop(0,99); }
   if (myRec.IsKeyPress(KEY_KEY_Q)) { cube->setFrameLoop(100,200); }

   if (oCollision(me, me2)) me2->setPosition(vector3df(10,-10,0));

    if (myRec.IsKeyDown(KEY_KEY_W)) oMove(me, 1,0,0);
    if (myRec.IsKeyDown(KEY_KEY_S)) oMove(me, -1,0,0);

    if (myRec.IsKeyDown(KEY_KEY_A)) oTurn(me, 0,-5,0);
    if (myRec.IsKeyDown(KEY_KEY_D)) oTurn(me, 0,5,0);

    camera->setTarget(me->getPosition());

   ////////// END GAME ///////

   driver->beginScene(true, true, SColor(0,120,120,120));
   smgr->drawAll();
   driver->endScene();

  }
 }


 // Уничтожаем игровой мир
 device->closeDevice();
 device->drop();

 return 1;
}
