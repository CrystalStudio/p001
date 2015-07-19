// ФУНКЦИИ //
/////////////////////////////////////////////////////

// Функция столкновения
bool oCollision(ISceneNode* one, ISceneNode* two)
{
  return (one->getTransformedBoundingBox().intersectsWithBox(two->getTransformedBoundingBox()));
}


// Создание куба
ISceneNode* oCreateCube(f32 x, f32 y, f32 z, char path[250])
{
  ISceneNode* cube= smgr->addCubeSceneNode();
  cube->setPosition(vector3df(x, y, z));
  cube->setMaterialTexture(0, driver->getTexture(path));
  cube->setMaterialFlag(EMF_LIGHTING ,0);
  return cube;
}


// Движение объекта
void oTranslation(ISceneNode* o, f32 x, f32 y, f32 z)
{
  o->setPosition(o->getPosition()+vector3df(x, y, z));
}


// Движение в направлении
void oMove(ISceneNode* o, f32 x, f32 y, f32 z)
{
  vector3df move; matrix4 mat;
  move = vector3df(x,y,z);
  mat.setRotationDegrees(o->getRotation());
  mat.transformVect(move);
  o->setPosition(o->getPosition() + move);
}


// Вращение объекта
void oTurn(ISceneNode* o, f32 x, f32 y, f32 z)
{
  o->setRotation(o->getRotation() + vector3df(x,y,z));
}


// Загрузка анимированной модели из файла
IAnimatedMeshSceneNode* oLoadAnimMesh(f32 x, f32 y, f32 z, char path[250])
{
  IAnimatedMeshSceneNode* o = smgr->addAnimatedMeshSceneNode(smgr->getMesh(path));
  o->setPosition(vector3df(x, y, z));
  o->addShadowVolumeSceneNode();
  return o;
}

// Загрузка анимированной модели из файла
IAnimatedMeshSceneNode* oLoadAnimMeshX(f32 x, f32 y, f32 z, char path[250])
{
  IAnimatedMeshSceneNode* o = smgr->addAnimatedMeshSceneNode(smgr->getMesh(path));
  o->setPosition(vector3df(x, y, z));
  o->setFrameLoop(0,0);
  //o->addShadowVolumeSceneNode();
  return o;
}

// Загрузка статической модели из файла
IMeshSceneNode* oLoadStaticMesh(f32 x, f32 y, f32 z, char path[250])
{
  IMeshSceneNode* o= smgr->addOctreeSceneNode(smgr->getMesh(path), 0, 0);
  o->setPosition(vector3df(x,y,z));
  return o;
}

// Создание селектора и аниматора для столкновений и привязка к объектам
void setCollision(IMeshSceneNode* one, IAnimatedMeshSceneNode* two)
{
  ITriangleSelector* selector = smgr->createOctreeTriangleSelector(one->getMesh(), one, 128);
  one->setTriangleSelector(selector);

  meta->addTriangleSelector(selector);

  ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
        meta,
        two, vector3df(2,2,2),
        vector3df(0,-10,0), vector3df(0,0,0));

  selector->drop();
  two->addAnimator(anim);
  anim->drop();
}


//////////////////////////////////////////////////////
// ФУНКЦИИ //

