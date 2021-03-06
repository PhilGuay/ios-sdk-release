//
//  TTPresenceData.h
//  TTKit
//
//  Created by Oren Zitoun on 5/1/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TTPresenceDataObserver;

/**
 *  When set to the type property, marks the respective TTUser as available
 */
FOUNDATION_EXPORT NSString *_Nonnull const kTTKitPresenceDataTypeAvailable;

/**
 *  When set to the type property, marks the respective TTUser as unavailable
 */
FOUNDATION_EXPORT NSString *_Nonnull const kTTKitPresenceDataTypeUnavailable;

/**
 *  TTPresenceData describes a user's status in the system - mostly if he is online or not, while providing the user's status as well.
 */
@interface TTPresenceData : NSObject

/**
 *  Token of TTUser to which of which presence data is detailed in this insatnce.
 */
@property (nullable, nonatomic, strong) NSString *userToken;

/**
 *  If type equals 'available', the available property will be YES. Any other value switches it to 'NO'.
 */
@property (nullable, nonatomic, strong) NSString *type;

/**
 *  User’s status message tagline.
 */
@property (nullable, nonatomic, strong) NSString *status;

/**
 *  YES when user is available, NO otherwise.
 */
@property (nonatomic, assign) BOOL available;

/**
 * Block that is called when Presence data type is changed
 */
@property (nullable, nonatomic, copy) void (^typeChangedBlock)(NSString* _Nullable) DEPRECATED_MSG_ATTRIBUTE("Use TTPresenceDataObserver instead.");

/**
 * Block that is called when Presence data status is changed
 */
@property (nullable, nonatomic, copy) void (^statusChangedBlock)(NSString* _Nullable) DEPRECATED_MSG_ATTRIBUTE("Use TTPresenceDataObserver instead.");

/**
 *  Add an observer to track presence and user status changes.
 */
- (void)addObserver:(id<TTPresenceDataObserver> _Nonnull)observer;

/**
 *  Remove an observer.
 */
- (void)removeObserver:(id<TTPresenceDataObserver> _Nonnull)observer;

@end

/**
 @abstract The `TTPresenceDataObserver` notifies its receiver when there's a change in the user online availability or when the user status changed.
 */
@protocol TTPresenceDataObserver <NSObject>

@optional
- (void)presenceDataChanged:(NSString *_Nonnull)available;
- (void)userStatusChanged:(NSString  *_Nonnull)userStatus;

@end
