// ҵ�����
class Stream {
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() { }
};

// ������
class FileStream : public Stream {
public:
    virtual char Read(int number) {
        // ���ļ���
    }

    virtual void Seek(int position) {
        // ��λ�ļ���
    }

    virtual void Write(char data) {
        // д�ļ���
    }
};

class NetworkStream : public Stream {
public:
    virtual char Read(int number) {
        // ��������
    }

    virtual void Seek(int position) {
        // ��λ������
    }

    virtual void Write(char data) {
        // д������
    }
};

class MemoryStream : public Stream {
public:
    virtual char Read(int number) {
        // ���ڴ���
    }

    virtual void Seek(int position) {
        // ��λ�ڴ���
    }

    virtual void Write(char data) {
        // д�ڴ���
    }
};

// ��չ�������̳� Stream ������Ϊ�˽ӿڹ淶

class DecoratorStream : public Stream {
protected:
    Stream *stream; // = new xxxStream();

    DecoratorStream(Stream* stm) : stream(stm) {

    }
};

class CryptoStream : public DecoratorStream {
public:
    CryptoStream(Stream *stm) : DecoratorStream(stm) {

    }

    virtual char Read(int number) {
        // ����ļ��ܲ���...
        stream->Read(number);
    }

    virtual void Seek(int position) {
        // ����ļ��ܲ���...
        stream->Seek(position);
        // ����ļ��ܲ���...
    }

    virtual void Write(char data) {
        // ����ļ��ܲ���...
        stream->Write(data);
        // ����ļ��ܲ���...
    }
};

class BufferedStream : public DecoratorStream {
public:
    BufferedStream(Stream *stm) : DecoratorStream(stm) {

    }

    virtual char Read(int number) {
        // ����Ļ������...
        stream->Read(number);
    }

    virtual void Seek(int position) {
        // ����Ļ������...
        stream->Seek(position);
        // ����Ļ������...
    }

    virtual void Write(char data) {
        // ����Ļ������...
        stream->Write(data);
        // ����Ļ������...
    }
};

void Progress() {
    // ����ʱװ��
    FileStream *s1 = new FileStream(); // �޲���
    CryptoStream *s2 = new CryptoStream(s1); // ����
    BufferedStream *s3 = new BufferedStream(s1); // ����
    BufferedStream *s4 = new BufferedStream(s2); // ���� + ����
}