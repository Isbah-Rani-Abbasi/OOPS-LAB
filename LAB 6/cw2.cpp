#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;

public:
    MediaFile(string path, double sz) : filePath(path), size(sz) {}
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual void info() {
        cout << "File: " << filePath << ", Size: " << size << "MB\n";
    }
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    string resolution;

public:
    VisualMedia(string path, double sz, string res) : MediaFile(path, sz), resolution(res) {}
    virtual void display() {
        cout << "Resolution: " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(string path, double sz, int rate) : MediaFile(path, sz), sampleRate(rate) {}
    virtual void sound() {
        cout << "Sample Rate: " << sampleRate << "Hz\n";
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double sz, string res)
        : MediaFile(path, sz), VisualMedia(path, sz, res) {}
    void play() override {
        info(); display();
        cout << "Displaying image\n";
    }
    void stop() override {
        cout << "Closing image\n";
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double sz, int rate)
        : MediaFile(path, sz), AudioMedia(path, sz, rate) {}
    void play() override {
        info(); sound();
        cout << "Playing audio\n";
    }
    void stop() override {
        cout << "Stopping audio\n";
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double sz, string res, int rate)
        : MediaFile(path, sz), VisualMedia(path, sz, res), AudioMedia(path, sz, rate) {}
    void play() override {
        info(); display(); sound();
        cout << "Playing video\n";
    }
    void stop() override {
        cout << "Stopping video\n";
    }
};

int main() {
    const int n = 3;
    MediaFile** library = new MediaFile*[n];
    library[0] = new ImageFile("pic.jpg", 5.2, "1920x1080");
    library[1] = new AudioFile("song.mp3", 3.1, 44100);
    library[2] = new VideoFile("movie.mp4", 1500, "3840x2160", 48000);

    for (int i = 0; i < n; ++i) {
        library[i]->play();
        library[i]->stop();
        cout << endl;
    }

    for (int i = 0; i < n; ++i) delete library[i];
    delete[] library;

    return 0;
}

