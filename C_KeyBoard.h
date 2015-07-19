// Класс Обработчик Событий
class MyReceiver : public IEventReceiver
{
public:
  virtual bool OnEvent(const SEvent& event)
  {
    if(event.EventType == EET_KEY_INPUT_EVENT)
      {
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if((event.KeyInput.PressedDown) && (KeyAcceptPressed[event.KeyInput.Key]))
          {
            KeyIsPressed[event.KeyInput.Key] = true;
            KeyAcceptPressed[event.KeyInput.Key] = false;
            anyKey= true;
          }
        if(!event.KeyInput.PressedDown)
          {
            anyKey= false;
            KeyIsPressed[event.KeyInput.Key] = false;
            KeyAcceptPressed[event.KeyInput.Key] = true;
          }
      }
    return false;
  }
  virtual bool IsKeyPress(EKEY_CODE keyCode)
  {
    bool pressed= KeyIsPressed[keyCode];
    KeyIsPressed[keyCode] = false;
    return pressed;
  }

  virtual bool IsAnyKeyDown() const
  {
    return anyKey;
  }

  virtual bool IsKeyDown(EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }

  MyReceiver()
  {
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
      {
        KeyIsDown[i] = false;
        KeyIsPressed[i] = false;
        KeyAcceptPressed[i] = true;
      }
    anyKey= false;
  }
private:
  bool KeyIsDown[KEY_KEY_CODES_COUNT];
  bool KeyIsPressed[KEY_KEY_CODES_COUNT];
  bool KeyAcceptPressed[KEY_KEY_CODES_COUNT];
  bool anyKey;
};

// Объяект класса
MyReceiver myRec;


