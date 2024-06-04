

#include <map>
#include <string>
#include "key_mapping.cpp"

namespace core
{
  enum KeyCode {
      KEY_A = 'a',
      KEY_D = 'd',
      KEY_W = 'w',
      KEY_S = 's',
      // Add other keys as needed
  };

  
class Input 
{
  private:
    static std::map<unsigned char, bool> KeyTable;
    static std::map<unsigned char, bool> KeyDownTable;

  public:
    static bool getKeyDown(KeyCode key) {
      if (KeyDownTable[key]) {
          KeyDownTable[key] = false; // Reset after the first check
          return true;
      }
      return false;
    }

    static bool getKey(KeyCode key) {
      return KeyTable[key];
    }

    static float getAxisRaw(std::string axisName) {
      if (axisName == "Horizontal") {
          if (getKey(KEY_A)) return -1.0f;
          if (getKey(KEY_D)) return 1.0f;
      } else if (axisName == "Vertical") {
          if (getKey(KEY_W)) return 1.0f;
          if (getKey(KEY_S)) return -1.0f;
      }
      return 0.0f;
    }

    static void updateKeyState(unsigned char key, bool state = true) {
      bool oldState = KeyTable[key];
      KeyTable[key] = state;
      if (state && !oldState) {
          KeyDownTable[key] = true; // Register key down event
      }
    }

    static void resetKeyStates() {
      for (auto& kv : KeyTable) {
          kv.second = false;
      }
    }
};

std::map<unsigned char, bool> Input::KeyTable;
std::map<unsigned char, bool> Input::KeyDownTable;
}


