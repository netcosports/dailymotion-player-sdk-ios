//  DailymotionPlayerViewController.h
//
//  Created by Olivier Poitrey on 26/09/11.
//  Copyright 2011 Dailymotion. All rights reserved.

#import <UIKit/UIKit.h>

@class DMPlayerViewController;

// The DMPlayerDelegate protocol defines optional methods for a delegate of DMPlayerViewController.
@protocol DMPlayerDelegate <NSObject>

@optional

/* Called when player emit an event.
 @param player The player which emited the event
 @param eventName The name of the emited event
 @param payload */
- (void)dailymotionPlayer:(DMPlayerViewController *)player didReceiveEvent:(NSString *)eventName withPayload:(NSDictionary *)payload;

@end

/* The DMPlayerViewController class implements a wrapper around the Dailymtion HTML5 player
 so it can be easily controlled. */
@interface DMPlayerViewController : UIViewController <UIWebViewDelegate>

#pragma mark - Initializing a Player
/* Initialize a video player with paramsters
 @param params  A dictionary containing initalization parameters.
                See http://www.dailymotion.com/doc/api/player.html#parameters for a list of supported parameters. */
- (id)initWithParams:(NSDictionary *)params;

/* Initialize a video player using a video id
 @param videoId The id of a video. */
- (id)initWithVideo:(NSString *)videoId;

/* Initialize a video player using a video id
 @param videoId The id of a video.
 @param params  A dictionary containing initalization parameters.
                See http://www.dailymotion.com/doc/api/player.html#parameters for a list of supported parameters. */
- (id)initWithVideo:(NSString *)videoId params:(NSDictionary *)params;

#pragma mark - Player Properties
// Determines whether the media resource plays automatically when available (read-only).
@property(nonatomic, readonly) BOOL autoplay;

// The current playback position in seconds. Set this value to seek in the video.
@property(nonatomic, assign) float currentTime;

// The part of the media resource that have been downloaded in seconds (read-only).
@property(nonatomic, readonly) float bufferedTime;

// The length of the media resource in seconds (read-only).
@property(nonatomic, readonly) float duration;

// Indicates whether the element is seeking (read-only).
@property(nonatomic, readonly) BOOL seeking;

// Indicates whether the media is paused (read-only).
@property(nonatomic, readonly) BOOL paused;

// Indicates whether the media played to the end (read-only).
@property(nonatomic, readonly) BOOL ended;

// Determines whether the audio content should be muted. Set this value to mute/unmute the sound.
@property(nonatomic, assign) BOOL muted;

// The volume of the video between 0 and 1.
@property(nonatomic, assign) float volume;

// Indicates whether the video is displayed fullscreen.
@property(nonatomic, assign) BOOL fullscreen;

// The last error that occurend for this player.
@property(nonatomic, readonly) NSError *error;

// The base URL for the player. Default is http://www.dailymotion.com.
@property(nonatomic, copy) NSString *webBaseURLString;

// Allows to control if external URLs show an alert or directly jump to Safari. Default is false.
@property(nonatomic, assign) BOOL autoOpenExternalURLs;

#pragma mark - Controlling Playback
// Start the video playback.
- (void)play;

// Toggle the video playback.
- (void)togglePlay;

// Pause the video playback.
- (void)pause;

/* When player is initialized with fullscreen-action='trigger_event' parameter, 
 this method is used to notify the application has successfly achieved the fullscreen transition. */
- (void)notifyFullscreenChange;

/* Load another video in the player by specifying its id.
 @param videoId The id of the video to load. */
- (void)load:(NSString *)videoId;

/* Load another video in the player by specifying its id and updating the associated parameters
 @param videoId The id of the video to load.
 @param params  A dictionary containing initalization parameters.
                See http://www.dailymotion.com/doc/api/player.html#parameters for a list of supported parameters. */
- (void)loadVideo:(NSString *)videoId withParams:(NSDictionary *)params;

#pragma mark - Calling Raw API Methods
/* Call player API method.
   See `Player API Reference <http://www.dailymotion.com/doc/api/player.html#api-reference>` for more info.
 @param method The method name to call
 @param arg The argument to pass to the method (if any) */
- (void)api:(NSString *)method arg:(NSString *)arg;

/* Call player API method.
   See `Player API Reference <http://www.dailymotion.com/doc/api/player.html#api-reference>` for more info.
 @param method The method name to call */
- (void)api:(NSString *)method;

#pragma mark - Delegate Access
// The player delegate to send player events to.
@property(nonatomic, weak) id<DMPlayerDelegate> delegate;

@end
