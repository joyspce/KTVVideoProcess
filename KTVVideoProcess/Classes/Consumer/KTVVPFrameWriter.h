//
//  KTVVPFrameWriter.h
//  KTVVideoProcessDemo
//
//  Created by Single on 2018/3/21.
//  Copyright © 2018年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "KTVVPContext.h"
#import "KTVVPFrameInput.h"
#import "KTVVPGLDefines.h"

@interface KTVVPFrameWriter : NSObject <KTVVPFrameInput>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithContext:(KTVVPContext *)context videoSize:(KTVVPGLSize)videoSize;

@property (nonatomic, strong, readonly) KTVVPContext * context;

@property (nonatomic, copy, readonly) NSError * error;

@property (nonatomic, copy) NSURL * outputFileURL;
@property (nonatomic, copy) AVFileType outputFileType;      // default is AVFileTypeQuickTimeMovie.

@property (nonatomic, assign, readonly) KTVVPGLSize videoSize;
@property (nonatomic, assign, readonly) CMTime videoStartTime;
@property (nonatomic, assign, readonly) CMTime videoPreviousFrameTime;
@property (nonatomic, assign) CGAffineTransform videoTransform;
@property (nonatomic, copy) NSDictionary * videoOutputSettings;
@property (nonatomic, copy) NSDictionary * videoSourcePixelBufferAttributes;

@property (nonatomic, assign) NSTimeInterval asyncDelayInterval;       // default is 0.


#pragma mark - Control

@property (nonatomic, assign) BOOL paused;

- (BOOL)startRecording;
- (void)finishRecordingWithCompletionHandler:(void (^)(BOOL success))completionHandler;
- (void)cancelRecordingWithCompletionHandler:(void (^)(BOOL success))completionHandler;

@end