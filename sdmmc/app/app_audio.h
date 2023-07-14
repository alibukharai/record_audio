
/*
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#pragma once

#define DEBUG_SAVE_PCM      (1)
#define PCM_ONE_CHANNEL     (1)
#define MAX_FILE_SIZE       (1*1024*1024)
#define RECORD_NAME         "/spiffs/record.wav"

typedef struct {
    // The "RIFF" chunk descriptor
    uint8_t ChunkID[4];//表示文件"RIFF"文件
    int32_t ChunkSize;//除了RIFF及自己之外，整个文件的长度，即文件总字节数减去8字节
    uint8_t Format[4];//文件类型头，表示一个"WAVE"文件
    // The "fmt" sub-chunk
    uint8_t Subchunk1ID[4];//格式表示符 “fmt “
    int32_t Subchunk1Size;//表示fmt数据块即subchunk1除了Subchunk1 ID和Subchunk1 Size之后剩下的长度，一般为16, 大于16表示存在扩展区域，可选值为16、18、20、40等
    int16_t AudioFormat;//  编码格式，即压缩格式，0x01表示pcm格式，无压缩，参见表3
    int16_t NumChannels;//  通道数
    int32_t SampleRate;//采样率，比如""表示44100采样率
    int32_t ByteRate;//码率： 采样率x位深度x通道数/8 比如双通道的44.1K 16位采样的码率为176400
    int16_t BlockAlign;//采样一次，占内存大小 ： 位深度x通道数/8
    int16_t BitsPerSample;//采样深度
    // The "data" sub-chunk
    uint8_t Subchunk2ID[4];//音频数据的总长度，即文件总字节数减去wav文件头的长度
    int32_t Subchunk2Size;//数据部分的长度
} wav_header_t;

typedef void (*audio_play_finish_cb_t)(void);

void sr_handler_task(void *pvParam);

/**
 * @brief The buffer to hold the recorded audio.
 */
extern volatile uint8_t *record_audio_buffer;
extern volatile uint8_t *audio_rx_buffer;

esp_err_t audio_play_task(void *filepath);

void audio_record_init();

void audio_record_save(int16_t *audio_buffer, int audio_chunksize);

void audio_register_play_finish_cb(audio_play_finish_cb_t cb);