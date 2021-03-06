#pragma once
extern "C" {
	#include "libavcodec/avcodec.h"
}

class VideoDecoder {
public:
	VideoDecoder(AVCodecParameters* codec_param);
	~VideoDecoder();
	void operator()(AVFrame* frame, int &finished, AVPacket* packet);
	unsigned width() const;
	unsigned height() const;
	AVPixelFormat pixel_format() const;
private:
	AVCodecContext* codec_context_{};
	bool decode(AVFrame* frame, AVPacket* packet);
};
