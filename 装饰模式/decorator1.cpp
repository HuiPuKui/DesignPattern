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

// ��չ����
class CryptoFileStream : public FileStream {
public:
    virtual char Read(int number) {
        // ����ļ��ܲ���...
        FileStream::Read(number);
    }

    virtual void Seek(int position) {
        // ����ļ��ܲ���...
        FileStream::Seek(position);
        // ����ļ��ܲ���...
    }

    virtual void Write(char data) {
        // ����ļ��ܲ���...
        FileStream::Write(data);
        // ����ļ��ܲ���...
    }
};

class CryptoNetworkStream : public NetworkStream {
public:
    virtual char Read(int number) {
        // ����ļ��ܲ���...
        NetworkStream::Read(number);
    }

    virtual void Seek(int position) {
        // ����ļ��ܲ���...
        NetworkStream::Seek(position);
        // ����ļ��ܲ���...
    }

    virtual void Write(char data) {
        // ����ļ��ܲ���...
        NetworkStream::Write(data);
        // ����ļ��ܲ���...
    }
};

class CryptoMemoryStream : public MemoryStream {
public:
    virtual char Read(int number) {
        // ����ļ��ܲ���...
        MemoryStream::Read(number);
    }

    virtual void Seek(int position) {
        // ����ļ��ܲ���...
        MemoryStream::Seek(position);
        // ����ļ��ܲ���...
    }

    virtual void Write(char data) {
        // ����ļ��ܲ���...
        MemoryStream::Write(data);
        // ����ļ��ܲ���...
    }
};

class BufferedFileStream : public FileStream {
    // ...
};

class BufferedNetworkStream : public NetworkStream {
    // ...
};

class BUfferedMemoryStream : public MemoryStream {
    // ...
};

class CryptoBufferedFileStream : public FileStream {
public:
    virtual char Read(int number) {
        // ����ļ��ܲ���...
        // ����Ļ������...
        FileStream::Read(number);
    }

    virtual void Seek(int position) {
        // ����ļ��ܲ���...
        // ����Ļ������...
        FileStream::Seek(position);
        // ����ļ��ܲ���...
        // ����Ļ������...
    }

    virtual void Write(char data) {
        // ����ļ��ܲ���...
        // ����Ļ������...
        FileStream::Write(data);
        // ����ļ��ܲ���...
        // ����Ļ������...
    }
};

void Progress() {
    // ����ʱװ��
    CryptoFileStream *fs1 = new CryptoFileStream();

    BufferedFileStream *fs2 = new BufferedFileStream();

    CryptoBufferedFileStream *fs3 = new CryptoBufferedFileStream();
}