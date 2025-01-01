#include <string>

class IProgress {
public:
    virtual void DoProgress(float value) = 0;
    ~IProgress() { }
};

class FileSplitter {
    std::string m_filePath;
    int m_fileNumber;

    // ProgressBar* m_progressBar; // ֪ͨ�ؼ�
    List<IProgress*> m_iprogressList; // ����֪ͨ���ƣ�֧�ֶ���۲���

public:
    FileSplitter(const std::string& filePath, int fileNumber) 
    : m_filePath(filePath), 
      m_fileNumber(fileNumber) {

    }

    void addIProgress(IProgress* iprogress) {
        m_iprogressList.push_back(iprogress);
    }

    void removeIProgress(IProgress* iprogress) {
        m_iprogressList.remove(iprogress);
    }

    void split() {
        // 1. ��ȡ���ļ�

        // 2. ��������С�ļ���д��
        for (int i = 0; i < m_fileNumber; i ++) {
            // ...
            float progressValue = m_fileNumber;
            progressValue = (i + 1) / progressValue;
            onProgress(progressValue);
        }
    }

protected:
    void onProgress(float value) {
        List<IProgress*>::Iterator itor = m_iprogressList.begin();
        while (itor != m_iprogressList.end())
            (*itor)->DoProgress(value); // ���½�����
            itor ++;
        }
    }
};