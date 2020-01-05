//
//  DVDTracker.h
//  chap_-10
//
//  Created by Jaran F on 15/06/2018.
//
#ifndef DVDTracker_h
#define DVDTracker_h
//|-----------> DEFINES <-----------|
#define kMaxDVDs                    4
#define kMaxTitleLength             256
#define kMaxCommentLength           256
//|-----------> STRUCTS <-----------|
struct DVDinfo {
    char rating;
    char title[ kMaxTitleLength ];
    char comment[ kMaxCommentLength ];
};
#endif /* DVDTracker_h */
