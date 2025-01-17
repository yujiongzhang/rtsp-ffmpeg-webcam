# 基于ffmpeg，可跨平台部署的 rtsp 视频播放器

## 1 项目简介

本项目为基于ffmpeg，可跨平台部署的 rtsp 视频播放器。目前可在 `x86_64_windows`， `x86_64_linux`，`arm64_linux` 的设备上进行部署。

以此为案例，可设计跨平台的显控软件、和嵌入式显示设备。

### 2 项目结构

```
rtsp-ffmpeg-webcam/
├── （项目主文件）
├── ffmpeg    					(ffmpeg 子项目)
    ├──(子项目主文件)
    ├──ffmpeg4/include64        (头文件)
    └──bin      
	    ├──amd64_linux          (x86_linux 的动态库)
		├──arm_inux       		(arm_linux 的动态库)
		└──amd64_win            (x86_win   的动态库)
```

## 3 环境配置

项目依赖

```
qt 5.14.2
ffmpeg 4.2.1
```

windows平台可以直接使用。

注：linux平台 ffmpeg中已有H.264的解码，但没有编码，所以需要先编译libx264，它是自由的H.264编码库，是x264项目的一部分。这里简介一下 x264 的编译流程

### 2.1 编译x264

源码下载：http://download.videolan.org/pub/videolan/x264/snapshots/

#### 2.1.1 x86_linux平台

```shell
tar xjvf x264-snapshot-20190917-2245-stable.tar.bz2

cd x264-snapshot-20190917-2245-stable/

./configure --prefix=/home/usrname/amd-lib/x264 --enable-shared --enable-static --disable-opencl --enable-pic --disable-asm

make && make install

# 生成了bin/include/lib三个文件夹及其内容
	x264/
	├── bin
	│   └── x264
	├── include
	│   ├── x264_config.h
	│   └── x264.h
	└── lib
	    ├── libx264.so -> libx264.so.152
	    ├── libx264.so.152
	    └── pkgconfig
	        └── x264.pc
	        
```

将安装目录下的bin/、include/、lib/下所需要文件拷贝到根目录下的对应位置。（这里笔者不知道为啥，引用为动态库却不行）

#### 2.1.1 arm_linux平台

如果是直接在 arm_linux 上编译的，步骤同上。

如果是需要在 x86 平台进行**交叉编译**，则 `./configure` 部分如下设置，即 使用 arm-linux 的编译器

```shell
./configure --prefix=/home/usrname/arm-lib/x264 --enable-shared --enable-static --host=arm-linux --cross-prefix=aarch64-linux-gnu- --disable-opencl --enable-pic --disable-asm
```

将安装目录下的bin/、include/、lib/下所需要文件拷贝到开发板根目录下的对应位置。



### 3.1 编译ffmpeg

本项目并不需要编译ffmpeg，为了使用方便，笔者已经将各个平台的动态库放在了`./ffmpeg/bin`文件夹中。完成2.1后可直接运行使用。

也可选择源码编译,可以参考下面的链接。源码下载：[Index of /releases (ffmpeg.org)](https://ffmpeg.org/releases/)


## 4 编译运行

ubunutu22.04 环境运行

![screen](./doc/screen.png)

windows11 环境运行

![screen2](./doc/screen2.png)

## 参考
[参考1](https://zhuanlan.zhihu.com/p/147315845)

[参考2](https://blog.csdn.net/weixin_44498318/article/details/112987608)

[参考3](https://blog.csdn.net/qq_39436605/article/details/82850507)