//
//  CCWebView.m
//  ChocoCore
//
//  Created by Chan Ivan on 11/29/13.
//  Copyright (c) 2013 Chan Ivan. All rights reserved.
//

#import "CCWebView.h"
#import <objc/message.h>
#import "CCWebBrowserView.h"
#import "CCWebScrollView.h"
#import "DefaultDelegateDefine.h"
#import "CCWebViewWebViewDelegate.h"
#import "WebViewDefine.h"
#import <QuartzCore/QuartzCore.h>

#define UIWEBVIEW_LIKE

@class WebFrameView, WebHistoryItem;
@interface CCWebView ()
{
    CCWebBrowserView    *_webBrowserView;
    CCWebScrollView     *_webScrollView;
}

@property (nonatomic, retain) DefaultPolicyDelegate         *policyDelegateHandler;
@property (nonatomic, retain) DefaultFrameLoadDelegate      *frameLoadDelegateHandler;
@property (nonatomic, retain) DefaultResourceLoadDelegate   *resourceLoadDelegateHandler;
@property (nonatomic, retain) DefaultUIDelegate             *UIDelegateHandler;

@property (nonatomic, retain) CCWebViewWebViewDelegate      *webViewDelegate;

@end

@implementation CCWebView

#pragma mark - Init & Dealloc
- (id)init
{
    self = [super init];
    if (self)
    {
        [self setup];
    }
    
    return self;
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self)
    {
        [self setup];
    }
    return self;
}

- (BOOL)setup
{
    self.backgroundColor = [UIColor orangeColor];
    
    //build BrowserView
    Class cls = NSClassFromString(@"UIWebBrowserView");
    _webBrowserView = [[cls alloc] initWithFrame:self.bounds];
    [_webBrowserView enableReachability];
    //[_webBrowserView set_editingDelegateForEverythingExceptForms:self];
    [cls preferredScrollDecelerationFactor];
    
    //build scrollView
    _webScrollView = [[CCWebScrollView alloc] initWithFrame:self.bounds];
    _webScrollView.backgroundColor = [UIColor purpleColor];
    _webScrollView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [_webScrollView addSubview:_webBrowserView];
    
    [_webBrowserView setTilingEnabled:YES];
    [_webBrowserView setLayoutTilesInMainThread:NO];
    [_webBrowserView setAutoresizes:YES];
    //[_webBrowserView setContentsPosition:CGRectMake(0, 0, 768, 944)];
    [_webBrowserView setDelegate:self];
    [_webBrowserView setSmoothsFonts:YES];
    [_webBrowserView setUsePreTimberlineTransparencyBehavior];
    
    {
#ifdef UIWEBVIEW_LIKE
        _webViewDelegate = [[CCWebViewWebViewDelegate alloc] initWithCCWebView:self];
        [[self webView] setUIDelegate:_webViewDelegate];
        [[self webView] setFrameLoadDelegate:_webViewDelegate];
        [[self webView] setResourceLoadDelegate:_webViewDelegate];
        [[self webView] setPolicyDelegate:_webViewDelegate];
        
#else
        _UIDelegateHandler = [[DefaultUIDelegate alloc] initWithCCWebView:self];
        [[self webView] setUIDelegate:self.UIDelegateHandler];
        
        _frameLoadDelegateHandler = [[DefaultFrameLoadDelegate alloc] initWithCCWebView:self];
        [[self webView] setFrameLoadDelegate:self.frameLoadDelegateHandler];
        
        _resourceLoadDelegateHandler = [[DefaultResourceLoadDelegate alloc] initWithCCWebView:self];
        [[self webView] setResourceLoadDelegate:self.resourceLoadDelegateHandler];
        
        _policyDelegateHandler = [[DefaultPolicyDelegate alloc] initWithCCWebView:self];
        [[self webView] setPolicyDelegate:self.policyDelegateHandler];
#endif
        
        //TODO:
        //[[self webView] setDownloadDelegate:self];
        //[[self webView] setHistoryDelegate:self];
    }
    
    [[self webView] _setFontFallbackPrefersPictographs:NO];
    
    WAKWindow *wakWindow = [[self webView] window];
    [wakWindow setRootLayer:[self layer]];
    
    id webPreferences = [[self webView] preferences];
    [webPreferences setOfflineWebApplicationCacheEnabled:YES];
    [webPreferences _setLocalStorageDatabasePath:[NSClassFromString(@"WebStorageManager") _storageDirectoryPath]];
    [webPreferences _setMinimumZoomFontSize: 0];
    [webPreferences _setAllowMultiElementImplicitFormSubmission: NO];
    
    [self addSubview:_webScrollView];
    
    [_webBrowserView _setDocumentType:4];
    [_webBrowserView setDetectsPhoneNumbers:YES];

    Class WebHistoryCls = NSClassFromString(@"WebHistory");
    if ([WebHistoryCls optionalSharedHistory] == nil)
    {
        id sharedHistory = [[WebHistoryCls alloc] init];
        [WebHistoryCls setOptionalSharedHistory:sharedHistory];
        [sharedHistory release];
    }
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(_didRotate:) name:@"UIWindowDidRotateNotification" object: nil];
    
    [self enableProgressChangeNotification:YES];
    
    return (_webScrollView && _webBrowserView);
}

- (void)dealloc
{
    [[self webView] _clearDelegates];
    
    [_policyDelegateHandler release];
    _policyDelegateHandler = nil;
    
    [_frameLoadDelegateHandler release];
    _frameLoadDelegateHandler = nil;
    
    [_resourceLoadDelegateHandler release];
    _resourceLoadDelegateHandler = nil;
    
    [_UIDelegateHandler release];
    _UIDelegateHandler = nil;
    
    _webBrowserView.delegate = nil;
    [_webBrowserView release];
    _webBrowserView = nil;
    
    [_webScrollView release];
    _webScrollView = nil;
    
    [super dealloc];
}

#pragma mark - Getters
- (CCWebBrowserView *)browserView
{
    return _webBrowserView;
}

- (CCWebBrowserView *)documentView
{
    return _webBrowserView;
}

- (UIScrollView *)scrollView
{
    return _webScrollView;
}

- (WebView *)webView
{
    return [self.browserView webView];
}

- (NSURLRequest *)request
{
    return [[[[self webView] mainFrame] dataSource] request];
}

- (BOOL)scalesPageToFit
{
    return NO;
}

- (UIDataDetectorTypes)dataDetectorTypes
{
    return [self.browserView dataDetectorTypes];
}

- (BOOL)allowsInlineMediaPlayback
{
    return [self.browserView  allowsInlineMediaPlayback];
}

- (BOOL)mediaPlaybackRequiresUserAction
{
    return [self.browserView  mediaPlaybackRequiresUserAction];
}

- (BOOL)mediaPlaybackAllowsAirPlay
{
    return [self.browserView  mediaPlaybackAllowsAirPlay];
}

- (BOOL)suppressesIncrementalRendering
{
    return [self.browserView  suppressesIncrementalRendering];
}

- (BOOL)keyboardDisplayRequiresUserAction
{
    return YES;
}

- (UIWebPaginationMode)paginationMode
{
    return UIWebPaginationModeUnpaginated;
}

- (UIWebPaginationBreakingMode)paginationBreakingMode
{
    return UIWebPaginationBreakingModePage;
}

- (CGFloat)pageLength
{
    return 0;
}

- (CGFloat)gapBetweenPages
{
    return 0;
}

- (NSUInteger)pageCount
{
    return 0;
}

-(NSString *)customUserAgent
{
    return [[self webView] customUserAgent];
}

#pragma mark - Setters
- (void)setScalesPageToFit:(BOOL)scalesPageToFit
{}

- (void)setDataDetectorTypes:(UIDataDetectorTypes)dataDetectorTypes
{
    [self.browserView  setDataDetectorTypes:dataDetectorTypes];
}

- (void)setAllowsInlineMediaPlayback:(BOOL)allowsInlineMediaPlayback
{
    [self.browserView  setAllowsInlineMediaPlayback:allowsInlineMediaPlayback];
}

- (void)setMediaPlaybackRequiresUserAction:(BOOL)mediaPlaybackRequiresUserAction
{
    [self.browserView  setMediaPlaybackRequiresUserAction:mediaPlaybackRequiresUserAction];
}

- (void)setMediaPlaybackAllowsAirPlay:(BOOL)mediaPlaybackAllowsAirPlay
{
    [self.browserView  setMediaPlaybackAllowsAirPlay:mediaPlaybackAllowsAirPlay];
}

- (void)setSuppressesIncrementalRendering:(BOOL)suppressesIncrementalRendering
{
    [self.browserView  setSuppressesIncrementalRendering:suppressesIncrementalRendering];
}

- (void)setKeyboardDisplayRequiresUserAction:(BOOL)keyboardDisplayRequiresUserAction
{

}

- (void)setPaginationMode:(UIWebPaginationMode)paginationMode
{}

- (void)setPaginationBreakingMode:(UIWebPaginationBreakingMode)paginationBreakingMode
{}

- (void)setPageLength:(CGFloat)pageLength
{}

- (void)setGapBetweenPages:(CGFloat)gapBetweenPages
{}

-(void)setCustomUserAgent:(NSString *)customUserAgent
{
    [[self webView] setCustomUserAgent:customUserAgent];
}

- (void)enableProgressChangeNotification:(BOOL)enable
{
    id coreWebView = [self webView];
	if(enable)
	{
		//监视进度
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(webViewProgressStepChange:)
													 name:@"WebProgressEstimateChangedNotification"
                                                   object:coreWebView];
	}
	else
	{
		[[NSNotificationCenter defaultCenter] removeObserver:self name:@"WebProgressEstimateChangedNotification" object:coreWebView];
	}
}

#pragma mark - Load Methods
- (void)loadRequest:(NSURLRequest *)request
{
    [self.browserView  loadRequest:request];
}

- (void)loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL
{
    [self.browserView  loadHTMLString:string baseURL:baseURL];
}

- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType textEncodingName:(NSString *)textEncodingName baseURL:(NSURL *)baseURL
{
    [self.browserView  loadData:data MIMEType:MIMEType textEncodingName:textEncodingName baseURL:baseURL];
}

#pragma mark - State
- (void)reload
{
    [[[self webView] mainFrame] reload];
}

- (void)stopLoading
{
    [[[self webView] mainFrame] stopLoading];
}

- (BOOL)canGoBack
{
    return [[self webView] canGoBack];
}

- (void)goBack
{
    [[self webView] goBack];
}

-(BOOL)canGoForward
{
    return [[self webView] canGoForward];
}

- (void)goForward
{
    [[self webView] goForward];
}

#pragma mark - Javascript
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script
{
    return [[self webView] stringByEvaluatingJavaScriptFromString:script];
}

#pragma mark - BrowserView Delegate
/**
 *
 *
 *  @param browserView
 */
- (void)webViewMainFrameDidFirstVisuallyNonEmptyLayoutInFrame:(CCWebBrowserView *)browserView
{}

/**
 *  Called after decidePolicyWithMIMEType & listener used
 *
 *  @param browserView
 */
- (void)webViewMainFrameDidCommitLoad:(CCWebBrowserView *)browserView
{
    if ([self.delegate respondsToSelector:@selector(webViewDidStartLoad:)])
    {
        [self.delegate webViewDidStartLoad:self];
    }
}

/**
 *  MainFrame did load finish
 *
 *  @param browserView
 */
- (void)webViewMainFrameDidFinishLoad:(CCWebBrowserView *)browserView
{
    if ([self.delegate respondsToSelector:@selector(webViewDidFinishLoad:)])
    {
        [self.delegate webViewDidFinishLoad:self];
    }
}

/**
 *  mainFrame fail
 *
 *  @param browserView
 *  @param error           
 */
- (void)webViewMainFrameDidFailLoad:(CCWebBrowserView *)browserView withError:(NSError *)error
{
    if ([self.delegate respondsToSelector:@selector(webView:didFailLoadWithError:)])
    {
        [self.delegate webView:self didFailLoadWithError:error];
    }
}

/**
 *  DocumentView notify the delegate when _updateSize was called
 *
 *  @param browserView
 *  @param frame    
 *  @param oldFrame
 */
- (void)view:(CCWebBrowserView *)browserView didSetFrame:(CGRect)frame oldFrame:(CGRect)oldFrame
{
    if (!CGRectEqualToRect(frame, oldFrame))
    {
        _webScrollView.contentSize = frame.size;
        
        if (frame.size.width > 0 && frame.size.height > 0)
        {
            //[webDocumentView redrawScaledDocument];
        }
    }
}

- (void)saveStateToHistoryItem:(WebHistoryItem *)item forWebView:(CCWebBrowserView *)browserView
{}

- (void)restoreStateFromHistoryItem:(WebHistoryItem *)item forWebView:(CCWebBrowserView *)browserView
{}

#pragma mark - Progress
- (void)webViewProgressStepChange:(NSNotification *)notification
{
    id value = [[notification object] valueForKey:@"estimatedProgress"];
    float step = [value floatValue];
    
    if ([self.delegate respondsToSelector:@selector(webView:loadingPercentageDidChange:)])
    {
		[self.delegate webView:self loadingPercentageDidChange:step];
    }
}

#pragma marl - Rotate
- (void)_didRotate:(NSNotification *)notification
{}

@end
