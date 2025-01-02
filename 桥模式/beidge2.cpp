#include <string>

class Messager {
protected:
    MessagerImp* messagerImp; // = new xxxMessagerBase();
public:
    Messager(MessagerImp* messagerImp) : messagerImp(messagerImp) { }
    virtual void Login(std::string username, std::string password) = 0;
    virtual void SendMessage(std::string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Messager() { }
};

class MessagerImp {
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() { }
};

// ƽ̨ʵ��
class PCMessagerImp : public MessagerImp {
public:
    virtual void PlaySound() {
        // ********
    }

    virtual void DrawShape() {
        // ********
    }

    virtual void WriteText() {
        // ********
    }

    virtual void Connect() {
        // ********
    }
};

class MobileMessagerImp : public MessagerImp {
public:
    virtual void PlaySound() {
        // ========
    }

    virtual void DrawShape() {
        // ========
    }

    virtual void WriteText() {
        // ========
    }

    virtual void Connect() {
        // ========
    }
};

// ҵ�����
class MessagerLite : public Messager {
public:
    MessagerLite(MessagerImp* MessagerImp) : Messager(messagerImp) {
        
    }

    virtual void Login(std::string username, std::string password) {
        messagerImp->Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        messagerImp->WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        messagerImp->DrawShape();
        // ...
    }
};

class MessagerPerfect : public Messager {
public:
    MessagerPerfect(MessagerImp* messageImp) : Messager(messageImp) {

    }

    virtual void Login(std::string username, std::string password) {
        messagerImp->PlaySound();
        // ...
        messagerImp->Connect();
        // ...
    }

    virtual void SendMessage(std::string message) {
        messagerImp->PlaySound();
        // ...
        messagerImp->WriteText();
        // ...
    }

    virtual void SendPicture(Image image) {
        messagerImp->PlaySound();
        // ...
        messagerImp->DrawShape();
        // ...
    }
};

void Process() {
    // ����ʱװ��
    MessagerImp* messagerImp = new PCMessagerImp();
    Messager* m = new MessagerPerfect(messagerImp);
}