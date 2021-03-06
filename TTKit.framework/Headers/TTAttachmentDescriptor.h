//
//  TTAttachmentDescriptor.h
//  TTKit
//
//  Created by Oren Zitoun on 4/14/14.
//  Copyright (c) 2014 TigerText, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class TTMessage;

/**
 *  TTAttachmentDescriptor describes an attachement added to a specific TTMessage.
 */
@interface TTAttachmentDescriptor : NSManagedObject

/**
 *  Index of attachment in TTMessage's attachmentDescriptors NSSet.
 */
@property (nullable, nonatomic, retain) NSNumber * index;

/**
 *  Is attachment downloaded and stored localy. Boolean value.
 */
@property (nullable, nonatomic, retain) NSNumber * isDownloaded;

/**
 *  If attachment was downloaded, this property contains its path on the device.
 */
@property (nullable, nonatomic, retain) NSString * localPath;

/**
 *  Attachment MIME type.
 */
@property (nonnull, nonatomic, retain) NSString * mimeType;

/**
 *  Size of attachment, in bytes.
 */
@property (nullable, nonatomic, retain) NSNumber * size;

/**
 *  Attachment type. See TTAttachmentType.
 */
@property (nonnull, nonatomic, retain) NSNumber * type;

/**
 *  The TTMessage to which this TTAttachmentDescriptor is linked.
 */
@property (nonnull, nonatomic, retain) TTMessage *message;

@end
