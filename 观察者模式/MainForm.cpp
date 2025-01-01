#include <FileSplitter.cpp>

class MainForm : public Form, public IProgress {
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProgressBar* progressBar;

public:
    void Button1_Click() {
        std::string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        ConsoleNotifier cn;

        FileSplitter splitter(filePath, number);

        splitter.addIProgress(this);
        splitter.addIProgress(&cn);

        splitter.splite();

        splitter.removeIProgress(this);
        splitter.removeIProgress(&cn);
    }

    virtual void DoProgress(float value) {
        progressBar->setValue(value);
    }
};

class ConsoleNotifier : public IProgress {
public:
    virtual void DoProgress(float value) {
        cout << ".";
    }
};