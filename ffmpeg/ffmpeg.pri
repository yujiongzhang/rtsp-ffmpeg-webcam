HEADERS += $$PWD/ffmpeghead.h
HEADERS += $$PWD/ffmpeg.h
SOURCES += $$PWD/ffmpeg.cpp

INCLUDEPATH += $$PWD/ffmpeg4/include64

win32{
    message("Building for Windows")
    LIBS += -L$$PWD/bin/amd64_win -lavcodec-58 -lavdevice-58 -lavfilter-7 -lavformat-58 -lavutil-56 -lpostproc-55 -lswresample-3 -lswscale-5
}

unix{
    contains(QT_ARCH, arm64){
        message("Building for ARM Linux")
        LIBS += -L$$PWD/bin/arm_linux -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lpostproc -lswresample -lswscale
        }
    else{
        message("Building for x86 Linux")
        LIBS += -L$$PWD/bin/amd64_linux -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lpostproc -lswresample -lswscale
    }
}
