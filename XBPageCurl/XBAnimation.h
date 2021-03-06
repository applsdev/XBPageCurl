//
//  XBAnimation.h
//  XBPageCurl
//
//  Created by xiss burg on 9/4/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * XBAnimation
 * Simple class for animations. It has a name, a duration and an update block that implements the animation behavior.
 * An interpolator block can also be set, which determines the rate that the input value is changed. Linear is the default.
 */
@interface XBAnimation : NSObject {
@private
    NSTimeInterval _duration;
    NSTimeInterval _elapsedTime;
    void (^_update)(double t);
    double (^_interpolator)(double t);
    void (^_completion)(void);
}

@property (nonatomic, copy) NSString *name;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, copy) double (^interpolator)(double t);

/**
 * Initializers
 * The update block argument is a double in the [0,1] interval.
 */
+ (id)animationWithName:(NSString *)name duration:(NSTimeInterval)duration update:(void (^)(double t))update;
+ (id)animationWithName:(NSString *)name duration:(NSTimeInterval)duration update:(void (^)(double t))update completion:(void (^)(void))completion;
+ (id)animationWithName:(NSString *)name duration:(NSTimeInterval)duration update:(void (^)(double t))update completion:(void (^)(void))completion interpolator:(double (^)(double t))interpolator;
- (id)initWithName:(NSString *)name duration:(NSTimeInterval)duration update:(void (^)(double t))update;
- (id)initWithName:(NSString *)name duration:(NSTimeInterval)duration update:(void (^)(double t))update completion:(void (^)(void))completion;
- (id)initWithName:(NSString *)name duration:(NSTimeInterval)duration update:(void (^)(double t))update completion:(void (^)(void))completion interpolator:(double (^)(double t))interpolator;

/**
 * Steps the animation forward using its interpolator. The dt parameter is the elapsed time in seconds.
 */
- (BOOL)step:(NSTimeInterval)dt;

@end


/**
 * Default interpolators.
 */
double (^XBAnimationInterpolatorLinear)(double t);
double (^XBAnimationInterpolatorEaseInOut)(double t);
double (^XBAnimationInterpolatorEaseIn)(double t);
double (^XBAnimationInterpolatorEaseOut)(double t);
