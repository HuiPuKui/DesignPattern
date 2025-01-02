#include <../工厂方法/SplitterFactory.cpp>

class BinarySplitter : public ISplitter {
public:
    void split() {
        // ...
    }
};

class TxtSplitter : public ISplitter {
public:
    void split() {
        // ...
    }
};

class PictureSplitter : public ISplitter {
public:
    void split() {
        // ...
    }
};

class VideoSplitter : public ISplitter {
public:
    void split() {
        // ...
    }
};

// 具体工厂
class BinarySplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new PictureSplitter();
    }
};

class VideoSplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() {
        return new VideoSplitter();
    }
};