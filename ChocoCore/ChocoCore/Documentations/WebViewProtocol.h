//
//  WebViewProtocol.h
//  ChocoCore
//
//  Created by Chan Ivan on 11/29/13.
//  Copyright (c) 2013 Chan Ivan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WebFrameProtocol.h"

#define OpaqueJSContext id
#define OpaqueJSValue id
#define String id
#define Page id

@protocol WebViewProtocol <NSObject>

/*
{
    WebViewPrivate                 	 _private
}
*/
@optional

+ (void)_initializeSafeCategory;
+ (void)_setAlwaysUsesComplexTextCodePath:(char)arg0 ;
+ (void)_removeUserStyleSheetsFromGroup:(id)arg0 world:(id)arg1 ;
+ (void)_addUserStyleSheetToGroup:(id)arg0 world:(id)arg1 source:(id)arg2 url:(id)arg3 whitelist:(id)arg4 blacklist:(id)arg5 ;
+ (id)_productivityDocumentMIMETypes;
+ (char)_canHandleRequest:(id)arg0 ;
+ (char)isCharacterSmartReplaceExempt:(unsigned short)arg0 isPreviousCharacter:(char)arg1 ;
+ (void)_setAcceleratedImageDecoding:(char)arg0 ;
+ (void)initialize;
+ (unsigned int)_cacheModel;
+ (void)_setCacheModel:(unsigned int)arg0 ;
+ (void)purgeInactiveFontData;
+ (char)_viewClass:(Class *)arg0 andRepresentationClass:(Class *)arg1 forMIMEType:(id)arg2 allowingPlugins:(char)arg3 ;
+ (Class)_getPDFRepresentationClass;
+ (char)canShowMIMETypeAsHTML:(id)arg0 ;
+ (char)_canHandleRequest:(id)arg0 forMainFrame:(char)arg1 ;
+ (char)shouldIncludeInWebKitStatistics;
+ (id)sharedWebInspectorServer;
+ (char)_representationExistsForURLScheme:(id)arg0 ;
+ (id)_generatedMIMETypeForURLScheme:(id)arg0 ;
+ (Class)_getPDFViewClass;
+ (void)_setPDFRepresentationClass:(Class)arg0 ;
+ (void)_setPDFViewClass:(Class)arg0 ;
+ (void)_registerPluginMIMEType:(id)arg0 ;
+ (void)_unregisterPluginMIMEType:(id)arg0 ;
+ (void)enableWebThread;
+ (void)_setAllowsRoundingHacks:(char)arg0 ;
+ (void)registerForMemoryNotifications;
+ (void)_makeAllWebViewsPerformSelector:(SEL)arg0 ;
+ (id)_standardUserAgentWithApplicationName:(id)arg0 osMarketingVersion:(id)arg1 ;
+ (void)_enableRemoteInspector;
+ (void)drainLayerPool;
+ (void)discardAllCompiledCode;
+ (void)releaseFastMallocMemory;
+ (void)_handleMemoryWarning;
+ (void)garbageCollectNow;
+ (void)_releaseMemoryNow;
+ (void)registerViewClass:(Class)arg0 representationClass:(Class)arg1 forMIMEType:(id)arg2 ;
+ (void)_unregisterViewClassAndRepresentationClassForMIMEType:(id)arg0 ;
+ (id)_MIMETypeForFile:(id)arg0 ;
+ (char)canShowMIMEType:(id)arg0 ;
+ (void)_addUserScriptToGroup:(id)arg0 world:(id)arg1 source:(id)arg2 url:(id)arg3 whitelist:(id)arg4 blacklist:(id)arg5 injectionTime:(int)arg6 injectedFrames:(int)arg7 ;
+ (void)_addUserStyleSheetToGroup:(id)arg0 world:(id)arg1 source:(id)arg2 url:(id)arg3 whitelist:(id)arg4 blacklist:(id)arg5 injectedFrames:(int)arg6 ;
+ (id)_standardUserAgentWithApplicationName:(id)arg0 ;
+ (void)_reportException:(OpaqueJSValue)arg0 inContext:(OpaqueJSContext)arg1 ;
+ (id)_supportedMIMETypes;
+ (void)willEnterBackgroundWithCompletionHandler:(id)arg0 ;
+ (char)_allowsRoundingHacks;
+ (char)canCloseAllWebViews;
+ (void)closeAllWebViews;
+ (char)canShowFile:(id)arg0 ;
+ (char)_acceleratedImageDecoding;
+ (void)_setAllowCookies:(char)arg0 ;
+ (char)_allowCookies;
+ (char)_isUnderMemoryPressure;
+ (void)_disableRemoteInspector;
+ (void)_disableAutoStartRemoteInspector;
+ (char)_isRemoteInspectorEnabled;
+ (void)_registerViewClass:(Class)arg0 representationClass:(Class)arg1 forURLScheme:(id)arg2 ;
+ (id)_decodeData:(id)arg0 ;
+ (void)_setShouldUseFontSmoothing:(char)arg0 ;
+ (char)_shouldUseFontSmoothing;
+ (void)_setMaximumImageSizeBeforeSubsampling:(unsigned int)arg0 ;
+ (unsigned int)_maximumImageSizeBeforeSubsampling;
+ (void)_addOriginAccessWhitelistEntryWithSourceOrigin:(id)arg0 destinationProtocol:(id)arg1 destinationHost:(id)arg2 allowDestinationSubdomains:(char)arg3 ;
+ (void)_removeOriginAccessWhitelistEntryWithSourceOrigin:(id)arg0 destinationProtocol:(id)arg1 destinationHost:(id)arg2 allowDestinationSubdomains:(char)arg3 ;
+ (void)_resetOriginAccessWhitelists;
+ (void)_addUserScriptToGroup:(id)arg0 world:(id)arg1 source:(id)arg2 url:(id)arg3 whitelist:(id)arg4 blacklist:(id)arg5 injectionTime:(int)arg6 ;
+ (void)_removeUserScriptFromGroup:(id)arg0 world:(id)arg1 url:(id)arg2 ;
+ (void)_removeUserStyleSheetFromGroup:(id)arg0 world:(id)arg1 url:(id)arg2 ;
+ (void)_removeUserScriptsFromGroup:(id)arg0 world:(id)arg1 ;
+ (void)_removeAllUserContentFromGroup:(id)arg0 ;
+ (void)_setDomainRelaxationForbidden:(char)arg0 forURLScheme:(id)arg1 ;
+ (void)_registerURLSchemeAsSecure:(id)arg0 ;
+ (void)_registerURLSchemeAsAllowingLocalStorageAccessInPrivateBrowsing:(id)arg0 ;
+ (void)_registerURLSchemeAsAllowingDatabaseAccessInPrivateBrowsing:(id)arg0 ;
+ (void)_setLoadResourcesSerially:(char)arg0 ;
+ (double)_defaultMinimumTimerInterval;
+ (char)_HTTPPipeliningEnabled;
+ (void)_setHTTPPipeliningEnabled:(char)arg0 ;
+ (void)_setTileCacheLayerPoolCapacity:(unsigned int)arg0 ;
+ (void)_cacheModelChangedNotification:(id)arg0 ;
+ (void)_preferencesRemovedNotification:(id)arg0 ;
+ (char)_canShowMIMEType:(id)arg0 allowingPlugins:(char)arg1 ;
+ (id)MIMETypesShownAsHTML;
+ (void)setMIMETypesShownAsHTML:(id)arg0 ;
+ (void)registerURLSchemeAsLocal:(id)arg0 ;
+ (void)_preflightSpellChecker;
+ (unsigned int)_didSetCacheModel;
+ (unsigned int)_maxCacheModelInAnyInstance;
+ (void)_preflightSpellCheckerNow:(id)arg0 ;
- (id)accessibilityContainer;
- (oneway void)release;
- (oneway void)_webcore_releaseOnWebThread;
- (char)_writeDataAtPath:(id)arg0 asArchive:(char)arg1 ;
- (char)_createSymlinkInDirectory:(id)arg0 pointingToPath:(id)arg1 ;
- (id)_quickLookContentFilePath;
- (id)userAgentForURL:(id)arg0 ;
- (void)complete:(id)arg0 ;
- (void)selectAll:(id)arg0 ;
- (id)typingAttributes;
- (void)clearText:(id)arg0 ;
- (void)cut:(id)arg0 ;
- (void)copy:(id)arg0 ;
- (void)makeTextWritingDirectionRightToLeft:(id)arg0 ;
- (void)makeTextWritingDirectionLeftToRight:(id)arg0 ;
- (void)toggleUnderline:(id)arg0 ;
- (void)paste:(id)arg0 ;
- (int)selectionAffinity;
- (id)initSimpleHTMLDocumentWithStyle:(id)arg0 frame:(CGRect)arg1 preferences:(id)arg2 groupName:(id)arg3 ;
- (void)setEditable:(char)arg0 ;
- (void)setCustomUserAgent:(id)arg0 ;
- (void)setSelectedDOMRange:(id)arg0 affinity:(int)arg1 ;
- (char)_setMediaLayer:(id)arg0 forPluginView:(id)arg1 ;
- (void)setContinuousSpellCheckingEnabled:(char)arg0 ;
- (void)moveBackward:(id)arg0 ;
- (void)moveForward:(id)arg0 ;
- (void)applyStyle:(id)arg0 ;
- (id)styleAtSelectionStart;
- (void)setTypingStyle:(id)arg0 ;
- (void)_setNetworkStateIsOnline:(char)arg0 ;
- (id)groupName;
- (void)_setWantsTelephoneNumberParsing:(char)arg0 ;
- (void)_setFixedLayoutSize:(CGSize)arg0 ;
- (char)_isProcessingUserGesture;
- (void)_setCustomFixedPositionLayoutRectInWebThread:(CGRect)arg0 synchronize:(char)arg1 ;
- (void)_setCustomFixedPositionLayoutRect:(CGRect)arg0 ;
- (void)_overflowScrollPositionChangedTo:(CGPoint)arg0 forNode:(id)arg1 isUserScroll:(char)arg2 ;
- (id)editingDelegate;
- (void)insertDictationPhrases:(id)arg0 metadata:(id)arg1 ;
- (void)toggleBold:(id)arg0 ;
- (void)toggleItalic:(id)arg0 ;
- (char)_pluginsAreRunning;
- (void)_setFontFallbackPrefersPictographs:(char)arg0 ;
- (id)stringByEvaluatingJavaScriptFromString:(id)arg0 ;
- (void)reload:(id)arg0 ;
- (char)goToBackForwardItem:(id)arg0 ;
- (void)goBack:(id)arg0 ;
- (void)goForward:(id)arg0 ;
- (char)canGoBack;
- (char)canGoForward;
- (int)_paginationMode;
- (void)_setPaginationMode:(int)arg0 ;
- (char)_paginationBehavesLikeColumns;
- (void)_setPaginationBehavesLikeColumns:(char)arg0 ;
- (float)_pageLength;
- (void)_setPageLength:(float)arg0 ;
- (float)_gapBetweenPages;
- (void)_setGapBetweenPages:(float)arg0 ;
- (unsigned int)_pageCount;
- (id)customUserAgent;
- (char)defersCallbacks;
- (void)delete:(id)arg0 ;
- (id)_touchEventRegions;
- (void)_setUIWebViewUserAgentWithBuildVersion:(id)arg0 ;
- (void)setAllowsRemoteInspection:(char)arg0 ;
- (void)setHostApplicationBundleId:(id)arg0 name:(id)arg1 ;
- (void)setDefersCallbacks:(char)arg0 ;
- (void)_insertNewlineInQuotedContent;
- (id)typingStyle;
- (void)scrollDOMRangeToVisible:(id)arg0 ;
- (void)updateLayoutIgnorePendingStyleSheets;
- (void)stopLoadingAndClear;
- (void)finalize;
- (void)close;
- (void)dealloc;
- (CGColorRef)backgroundColor;
- (id<WebFrameProtocol>)mainFrame;
- (void)setUsesPageCache:(char)arg0 ;
- (id)initWithFrame:(CGRect)arg0 ;
- (void)setResourceLoadDelegate:(id)arg0 ;
- (void)setFrameLoadDelegate:(id)arg0 ;
- (void)setPolicyDelegate:(id)arg0 ;
- (void)setPreferences:(id)arg0 ;
- (void)setTextSizeMultiplier:(float)arg0 ;
- (id)preferences;
- (float)textSizeMultiplier;
- (id)quickLookContentForURL:(id)arg0 ;
- (char)usesPageCache;
- (void)_close;
- (char)goBack;
- (char)goForward;
- (id)_UIDelegateForwarder;
- (id)UIDelegate;
- (char)_allowsMessaging;
- (id)_UIKitDelegate;
- (id)_UIKitDelegateForwarder;
- (void)setGroupName:(id)arg0 ;
- (void)stopLoading:(id)arg0 ;
- (void)_closeWindow;
- (void)_mouseDidMoveOverElement:(id)arg0 modifierFlags:(unsigned int)arg1 ;
- (id)_selectedOrMainFrame;
- (id)historyDelegate;
- (Page)page;
- (int)_keyboardUIMode;
- (void)_pushPerformingProgrammaticFocus;
- (void)_popPerformingProgrammaticFocus;
- (void)_setNeedsOneShotDrawingSynchronization:(char)arg0 ;
- (void)_scheduleCompositingLayerSync;
- (char)_isStopping;
- (id)_fixedPositionContent;
- (char)_canShowMIMEType:(id)arg0 ;
- (id)_UIDelegateForSelector:(SEL)arg0 ;
- (id)_frameLoadDelegateForwarder;
- (id)_resourceLoadDelegateForwarder;
- (id)_formDelegateForSelector:(SEL)arg0 ;
- (id)_deviceOrientationProvider;
- (id)resourceLoadDelegate;
- (id)downloadDelegate;
- (char)isContinuousSpellCheckingEnabled;
- (id)_editingDelegateForwarder;
- (char)smartInsertDeleteEnabled;
- (char)isSelectTrailingWhitespaceEnabled;
- (char)_shouldChangeSelectedDOMRange:(id)arg0 toDOMRange:(id)arg1 affinity:(int)arg2 stillSelecting:(char)arg3 ;
- (char)_isClosing;
- (id)undoManager;
- (void)deleteBackward:(id)arg0 ;
- (void)moveUp:(id)arg0 ;
- (void)moveDown:(id)arg0 ;
- (void)insertBacktab:(id)arg0 ;
- (void)insertTab:(id)arg0 ;
- (void)insertNewline:(id)arg0 ;
- (id<WebFrameProtocol>)_mainCoreFrame;
- (float)_realZoomMultiplier;
- (char)_realZoomMultiplierIsTextOnly;
- (void)_setZoomMultiplier:(float)arg0 isTextOnly:(char)arg1 ;
- (char)drawsBackground;
- (void)setDrawsBackground:(char)arg0 ;
- (char)shouldUpdateWhileOffscreen;
- (char)supportsTextEncoding;
- (char)_includesFlattenedCompositingLayersWhenDrawingToBitmap;
- (void)_stopAllPlugIns;
- (void)_startAllPlugIns;
- (id)selectedDOMRange;
- (CGSize)_fixedLayoutSize;
- (void)_addObject:(id)arg0 forIdentifier:(unsigned long)arg1 ;
- (id)_objectForIdentifier:(unsigned long)arg0 ;
- (void)_removeObjectForIdentifier:(unsigned long)arg0 ;
- (void)_didCommitLoadForFrame:(id)arg0 ;
- (id)_webMailDelegate;
- (id)_policyDelegateForwarder;
- (id)_formDelegate;
- (double)estimatedProgress;
- (void)setMainFrameDocumentReady:(char)arg0 ;
- (id)_downloadURL:(id)arg0 ;
- (void)_setGlobalHistoryItem:(id)arg0 ;
- (void)_stopAllPlugInsForPageCache;
- (void)_restorePlugInsFromCache;
- (String)_userAgentString;
- (id)_pluginForExtension:(id)arg0 ;
- (id)_pluginForMIMEType:(id)arg0 ;
- (id)_videoProxyPluginForMIMEType:(id)arg0 ;
- (id)mediaStyle;
- (id)scriptDebugDelegate;
- (id)policyDelegate;
- (void)setNextKeyView:(id)arg0 ;
- (id)previousValidKeyView;
- (void)scrollToBeginningOfDocument:(id)arg0 ;
- (void)scrollToEndOfDocument:(id)arg0 ;
- (void)scrollPageUp:(id)arg0 ;
- (void)scrollPageDown:(id)arg0 ;
- (void)scrollLineUp:(id)arg0 ;
- (void)scrollLineDown:(id)arg0 ;
- (id)_webcore_effectiveFirstResponder;
- (char)_useFixedLayout;
- (id)_geolocationProvider;
- (void)_geolocationDidChangePosition:(id)arg0 ;
- (void)_geolocationDidFailWithError:(id)arg0 ;
- (void)_resetAllGeolocationPermission;
- (void)_documentScaleChanged;
- (char)_isUsingAcceleratedCompositing;
- (char)maintainsInactiveSelection;
- (char)searchFor:(id)arg0 direction:(char)arg1 caseSensitive:(char)arg2 wrap:(char)arg3 startInSelection:(char)arg4 ;
- (id)elementAtPoint:(CGPoint)arg0 ;
- (char)_isPerformingProgrammaticFocus;
- (void)selectWord:(id)arg0 ;
- (char)searchFor:(id)arg0 direction:(char)arg1 caseSensitive:(char)arg2 wrap:(char)arg3 ;
- (void)alignCenter:(id)arg0 ;
- (void)alignJustified:(id)arg0 ;
- (void)alignLeft:(id)arg0 ;
- (void)alignRight:(id)arg0 ;
- (void)deleteBackwardByDecomposingPreviousCharacter:(id)arg0 ;
- (void)deleteForward:(id)arg0 ;
- (void)deleteToBeginningOfLine:(id)arg0 ;
- (void)deleteToBeginningOfParagraph:(id)arg0 ;
- (void)deleteToEndOfLine:(id)arg0 ;
- (void)deleteToEndOfParagraph:(id)arg0 ;
- (void)deleteToMark:(id)arg0 ;
- (void)deleteWordBackward:(id)arg0 ;
- (void)deleteWordForward:(id)arg0 ;
- (void)ignoreSpelling:(id)arg0 ;
- (void)indent:(id)arg0 ;
- (void)insertLineBreak:(id)arg0 ;
- (void)insertNewlineIgnoringFieldEditor:(id)arg0 ;
- (void)insertParagraphSeparator:(id)arg0 ;
- (void)insertTabIgnoringFieldEditor:(id)arg0 ;
- (void)makeTextWritingDirectionNatural:(id)arg0 ;
- (void)moveBackwardAndModifySelection:(id)arg0 ;
- (void)moveDownAndModifySelection:(id)arg0 ;
- (void)moveForwardAndModifySelection:(id)arg0 ;
- (void)moveLeft:(id)arg0 ;
- (void)moveLeftAndModifySelection:(id)arg0 ;
- (void)moveParagraphBackwardAndModifySelection:(id)arg0 ;
- (void)moveParagraphForwardAndModifySelection:(id)arg0 ;
- (void)moveRight:(id)arg0 ;
- (void)moveRightAndModifySelection:(id)arg0 ;
- (void)moveToBeginningOfDocument:(id)arg0 ;
- (void)moveToBeginningOfDocumentAndModifySelection:(id)arg0 ;
- (void)moveToBeginningOfLine:(id)arg0 ;
- (void)moveToBeginningOfLineAndModifySelection:(id)arg0 ;
- (void)moveToBeginningOfParagraph:(id)arg0 ;
- (void)moveToBeginningOfParagraphAndModifySelection:(id)arg0 ;
- (void)moveToBeginningOfSentence:(id)arg0 ;
- (void)moveToBeginningOfSentenceAndModifySelection:(id)arg0 ;
- (void)moveToEndOfDocument:(id)arg0 ;
- (void)moveToEndOfDocumentAndModifySelection:(id)arg0 ;
- (void)moveToEndOfLine:(id)arg0 ;
- (void)moveToEndOfLineAndModifySelection:(id)arg0 ;
- (void)moveToEndOfParagraph:(id)arg0 ;
- (void)moveToEndOfParagraphAndModifySelection:(id)arg0 ;
- (void)moveToEndOfSentence:(id)arg0 ;
- (void)moveToEndOfSentenceAndModifySelection:(id)arg0 ;
- (void)moveToLeftEndOfLine:(id)arg0 ;
- (void)moveToLeftEndOfLineAndModifySelection:(id)arg0 ;
- (void)moveToRightEndOfLine:(id)arg0 ;
- (void)moveToRightEndOfLineAndModifySelection:(id)arg0 ;
- (void)moveUpAndModifySelection:(id)arg0 ;
- (void)moveWordBackward:(id)arg0 ;
- (void)moveWordBackwardAndModifySelection:(id)arg0 ;
- (void)moveWordForward:(id)arg0 ;
- (void)moveWordForwardAndModifySelection:(id)arg0 ;
- (void)moveWordLeft:(id)arg0 ;
- (void)moveWordLeftAndModifySelection:(id)arg0 ;
- (void)moveWordRight:(id)arg0 ;
- (void)moveWordRightAndModifySelection:(id)arg0 ;
- (void)outdent:(id)arg0 ;
- (void)pageDown:(id)arg0 ;
- (void)pageDownAndModifySelection:(id)arg0 ;
- (void)pageUp:(id)arg0 ;
- (void)pageUpAndModifySelection:(id)arg0 ;
- (void)pasteAsPlainText:(id)arg0 ;
- (void)selectLine:(id)arg0 ;
- (void)selectParagraph:(id)arg0 ;
- (void)selectSentence:(id)arg0 ;
- (void)selectToMark:(id)arg0 ;
- (void)setMark:(id)arg0 ;
- (void)subscript:(id)arg0 ;
- (void)superscript:(id)arg0 ;
- (void)swapWithMark:(id)arg0 ;
- (void)transpose:(id)arg0 ;
- (void)underline:(id)arg0 ;
- (void)unscript:(id)arg0 ;
- (void)yank:(id)arg0 ;
- (void)yankAndSelect:(id)arg0 ;
- (void)centerSelectionInVisibleArea:(id)arg0 ;
- (void)uppercaseWord:(id)arg0 ;
- (void)lowercaseWord:(id)arg0 ;
- (void)capitalizeWord:(id)arg0 ;
- (void)insertText:(id)arg0 ;
- (void)unmarkAllTextMatches;
- (id)rectsForTextMatches;
- (id)inspector;
- (char)canBeRemotelyInspected;
- (void)setUIDelegate:(id)arg0 ;
- (void)setCurrentNodeHighlight:(id)arg0 ;
- (void)_removeFromAllWebViewsSet;
- (void)_addToAllWebViewsSet;
- (void)setApplicationNameForUserAgent:(id)arg0 ;
- (void)_updateScreenScaleFromWindow;
- (void)_wakWindowScreenScaleChanged:(id)arg0 ;
- (void)_preferencesChangedNotification:(id)arg0 ;
- (void)_preferencesChanged:(id)arg0 ;
- (void)_commonInitializationWithFrameName:(id)arg0 groupName:(id)arg1 ;
- (void)setMaintainsBackForwardList:(char)arg0 ;
- (void)_closePluginDatabases;
- (void)_clearDelegates;
- (void)_closeWithFastTeardown;
- (void)setHostWindow:(id)arg0 ;
- (id)preferencesIdentifier;
- (char)allowsRemoteInspection;
- (char)_needsPreHTML5ParserQuirks;
- (char)_needsUnrestrictedGetMatchedCSSRules;
- (char)interactiveFormValidationEnabled;
- (int)validationMessageTimerMagnification;
- (void)caretChanged;
- (void)_setFormDelegate:(id)arg0 ;
- (void)_setUIKitDelegate:(id)arg0 ;
- (void)setCaretChangeListener:(id)arg0 ;
- (void)removeAllCaretChangeListeners;
- (void)setWebMailDelegate:(id)arg0 ;
- (void)setDownloadDelegate:(id)arg0 ;
- (void)setEditingDelegate:(id)arg0 ;
- (void)setScriptDebugDelegate:(id)arg0 ;
- (char)_locked_plugInsAreRunningInFrame:(id)arg0 ;
- (void)_locked_recursivelyPerformPlugInSelector:(SEL)arg0 inFrame:(id)arg1 ;
- (id)backForwardList;
- (void)_synchronizeCustomFixedPositionLayoutRect;
- (void)setSmartInsertDeleteEnabled:(char)arg0 ;
- (unsigned int)countMatchesForText:(id)arg0 options:(unsigned int)arg1 highlight:(char)arg2 limit:(unsigned int)arg3 markMatches:(char)arg4 ;
- (char)findString:(id)arg0 options:(unsigned int)arg1 ;
- (id)currentNodeHighlight;
- (void)_setBrowserUserAgentProductVersion:(id)arg0 buildVersion:(id)arg1 bundleVersion:(id)arg2 ;
- (void)_dispatchPendingLoadRequests;
- (id)_initWithFrame:(CGRect)arg0 frameName:(id)arg1 groupName:(id)arg2 usesDocumentViews:(char)arg3 ;
- (void)_viewWillDrawInternal;
- (char)_viewClass:(Class *)arg0 andRepresentationClass:(Class *)arg1 forMIMEType:(id)arg2 ;
- (char)_isClosed;
- (void)_dispatchUnloadEvent;
- (void)_setResourceLoadSchedulerSuspended:(char)arg0 ;
- (id)_openNewWindowWithRequest:(id)arg0 ;
- (void)setIndicatingForRemoteInspector:(char)arg0 ;
- (id)hostApplicationBundleId;
- (id)hostApplicationName;
- (void)setRemoteInspectorUserInfo:(id)arg0 ;
- (id)remoteInspectorUserInfo;
- (void)_loadBackForwardListFromOtherView:(id)arg0 ;
- (id)_formDelegateForwarder;
- (void)_cacheResourceLoadDelegateImplementations;
- (void)_cacheFrameLoadDelegateImplementations;
- (void)_cacheScriptDebugDelegateImplementations;
- (void)_cacheHistoryDelegateImplementations;
- (id)caretChangeListener;
- (id)caretChangeListeners;
- (void)addCaretChangeListener:(id)arg0 ;
- (void)removeCaretChangeListener:(id)arg0 ;
- (id)_displayURL;
- (void)_setInViewSourceMode:(char)arg0 ;
- (char)_inViewSourceMode;
- (void)_setUseFastImageScalingMode:(char)arg0 ;
- (char)_inFastImageScalingMode;
- (char)_cookieEnabled;
- (void)_setCookieEnabled:(char)arg0 ;
- (void)_destroyAllPlugIns;
- (void)_clearBackForwardCache;
- (void)_setNeedsUnrestrictedGetMatchedCSSRules:(char)arg0 ;
- (void)_attachScriptDebuggerToAllFrames;
- (void)_detachScriptDebuggerFromAllFrames;
- (void)_setAllowsMessaging:(char)arg0 ;
- (id)_globalHistoryItem;
- (id)textIteratorForRect:(CGRect)arg0 ;
- (void)_setCatchesDelegateExceptions:(char)arg0 ;
- (char)_catchesDelegateExceptions;
- (void)_executeCoreCommandByName:(id)arg0 value:(id)arg1 ;
- (void)_setCustomHTMLTokenizerTimeDelay:(double)arg0 ;
- (void)_setCustomHTMLTokenizerChunkSize:(int)arg0 ;
- (void)_clearMainFrameName;
- (void)setSelectTrailingWhitespaceEnabled:(char)arg0 ;
- (void)setMemoryCacheDelegateCallsEnabled:(char)arg0 ;
- (char)areMemoryCacheDelegateCallsEnabled;
- (void)_setJavaScriptURLsAreAllowed:(char)arg0 ;
- (char)_postsAcceleratedCompositingNotifications;
- (void)_setPostsAcceleratedCompositingNotifications:(char)arg0 ;
- (void)_setBaseCTM:(CGAffineTransform)arg0 forContext:(CGContextRef)arg1 ;
- (void)setInteractiveFormValidationEnabled:(char)arg0 ;
- (void)setValidationMessageTimerMagnification:(int)arg0 ;
- (char)_isSoftwareRenderable;
- (void)_setIncludesFlattenedCompositingLayersWhenDrawingToBitmap:(char)arg0 ;
- (void)setTracksRepaints:(char)arg0 ;
- (char)isTrackingRepaints;
- (void)resetTrackedRepaints;
- (id)trackedRepaintRects;
- (void)_updateActiveState;
- (char)cssAnimationsSuspended;
- (void)setCSSAnimationsSuspended:(char)arg0 ;
- (void)_scaleWebView:(float)arg0 atOrigin:(CGPoint)arg1 ;
- (float)_viewScaleFactor;
- (void)_setUseFixedLayout:(char)arg0 ;
- (unsigned int)markAllMatchesForText:(id)arg0 caseSensitive:(char)arg1 highlight:(char)arg2 limit:(unsigned int)arg3 ;
- (unsigned int)countMatchesForText:(id)arg0 caseSensitive:(char)arg1 highlight:(char)arg2 limit:(unsigned int)arg3 markMatches:(char)arg4 ;
- (void)_setMinimumTimerInterval:(double)arg0 ;
- (char)_wantsTelephoneNumberParsing;
- (char)_webGLEnabled;
- (void)_setWebGLEnabled:(char)arg0 ;
- (id)initWithFrame:(CGRect)arg0 frameName:(id)arg1 groupName:(id)arg2 ;
- (id)frameLoadDelegate;
- (id)_focusedFrame;
- (float)_zoomMultiplier:(char)arg0 ;
- (id)customTextEncodingName;
- (id)_mainFrameOverrideEncoding;
- (id)_frameViewAtWindowPoint:(CGPoint)arg0 ;
- (id)_elementAtWindowPoint:(CGPoint)arg0 ;
- (char)_isLoading;
- (char)_isMIMETypeRegisteredAsPlugin:(id)arg0 ;
- (id)_initWithArguments:(id)arg0 ;
- (void)setShouldCloseWithWindow:(char)arg0 ;
- (char)shouldCloseWithWindow;
- (void)setPreferencesIdentifier:(id)arg0 ;
- (id)selectedFrame;
- (char)_canZoomOut:(char)arg0 ;
- (char)_canZoomIn:(char)arg0 ;
- (void)_zoomOut:(id)arg0 isTextOnly:(char)arg1 ;
- (void)_zoomIn:(id)arg0 isTextOnly:(char)arg1 ;
- (char)_canResetZoom:(char)arg0 ;
- (void)_resetZoom:(id)arg0 isTextOnly:(char)arg1 ;
- (id)applicationNameForUserAgent;
- (void)setMediaStyle:(id)arg0 ;
- (void)setCustomTextEncodingName:(id)arg0 ;
- (id)windowScriptObject;
- (id)hostWindow;
- (id)documentViewAtWindowPoint:(CGPoint)arg0 ;
- (void)setMainFrameURL:(id)arg0 ;
- (id)mainFrameURL;
- (id)mainFrameTitle;
- (id)mainFrameIconURL;
- (id)mainFrameDocument;
- (void)setShouldUpdateWhileOffscreen:(char)arg0 ;
- (void)takeStringURLFrom:(id)arg0 ;
- (void)reloadFromOrigin:(id)arg0 ;
- (char)canMakeTextSmaller;
- (void)makeTextSmaller:(id)arg0 ;
- (char)canMakeTextLarger;
- (void)makeTextLarger:(id)arg0 ;
- (char)canMakeTextStandardSize;
- (void)makeTextStandardSize:(id)arg0 ;
- (unsigned int)countMatchesForText:(id)arg0 inDOMRange:(id)arg1 options:(unsigned int)arg2 highlight:(char)arg3 limit:(unsigned int)arg4 markMatches:(char)arg5 ;
- (id)DOMRangeOfString:(id)arg0 relativeTo:(id)arg1 options:(unsigned int)arg2 ;
- (void)setTabKeyCyclesThroughElements:(char)arg0 ;
- (char)tabKeyCyclesThroughElements;
- (void)setHistoryDelegate:(id)arg0 ;
- (char)shouldClose;
- (char)canMarkAllTextMatches;
- (void)scrollDOMRangeToVisible:(id)arg0 withInset:(float)arg1 ;
- (char)allowsUndo;
- (void)setAllowsUndo:(char)arg0 ;
- (void)setPageSizeMultiplier:(float)arg0 ;
- (float)pageSizeMultiplier;
- (char)canZoomPageIn;
- (void)zoomPageIn:(id)arg0 ;
- (char)canZoomPageOut;
- (void)zoomPageOut:(id)arg0 ;
- (char)canResetPageZoom;
- (void)resetPageZoom:(id)arg0 ;
- (void)setMediaVolume:(float)arg0 ;
- (float)mediaVolume;
- (void)addVisitedLinks:(id)arg0 ;
- (void)removeVisitedLink:(id)arg0 ;
- (id)computedStyleForElement:(id)arg0 pseudoElement:(id)arg1 ;
- (char)_continuousCheckingAllowed;
- (void)registerForEditingDelegateNotification:(id)arg0 selector:(SEL)arg1 ;
- (id)editableDOMRangeForPoint:(CGPoint)arg0 ;
- (id)styleDeclarationWithText:(id)arg0 ;
- (char)isAutomaticQuoteSubstitutionEnabled;
- (char)isAutomaticLinkDetectionEnabled;
- (char)isAutomaticDashSubstitutionEnabled;
- (char)isAutomaticTextReplacementEnabled;
- (char)isAutomaticSpellingCorrectionEnabled;
- (void)replaceSelectionWithNode:(id)arg0 ;
- (void)replaceSelectionWithText:(id)arg0 ;
- (void)replaceSelectionWithMarkupString:(id)arg0 ;
- (void)replaceSelectionWithArchive:(id)arg0 ;
- (void)deleteSelection;
- (id)_responderForResponderOperations;
- (void)_performResponderOperation:(SEL)arg0 with:(id)arg1 ;
- (void)changeAttributes:(id)arg0 ;
- (void)changeBaseWritingDirection:(id)arg0 ;
- (void)changeBaseWritingDirectionToLTR:(id)arg0 ;
- (void)changeBaseWritingDirectionToRTL:(id)arg0 ;
- (void)changeColor:(id)arg0 ;
- (void)changeDocumentBackgroundColor:(id)arg0 ;
- (void)changeFont:(id)arg0 ;
- (void)changeSpelling:(id)arg0 ;
- (void)checkSpelling:(id)arg0 ;
- (void)copyFont:(id)arg0 ;
- (void)makeBaseWritingDirectionLeftToRight:(id)arg0 ;
- (void)makeBaseWritingDirectionRightToLeft:(id)arg0 ;
- (void)orderFrontSubstitutionsPanel:(id)arg0 ;
- (void)pasteAsRichText:(id)arg0 ;
- (void)pasteFont:(id)arg0 ;
- (void)performFindPanelAction:(id)arg0 ;
- (void)showGuessPanel:(id)arg0 ;
- (void)startSpeaking:(id)arg0 ;
- (void)stopSpeaking:(id)arg0 ;
- (void)takeFindStringFromSelection:(id)arg0 ;
- (void)toggleBaseWritingDirection:(id)arg0 ;
- (void)_replaceSelectionWithNode:(id)arg0 matchStyle:(char)arg1 ;
- (char)_selectionIsCaret;
- (char)_selectionIsAll;
- (void)_simplifyMarkup:(id)arg0 endNode:(id)arg1 ;
- (void)_retrieveKeyboardUIModeFromPreferences:(id)arg0 ;
- (char)_syncCompositingChanges;
- (char)_becomingFirstResponderFromOutside;
- (char)_needsOneShotDrawingSynchronization;
- (CGPoint)_convertPointFromRootView:(CGPoint)arg0 ;
- (CGRect)_convertRectFromRootView:(CGRect)arg0 ;
- (void)_setDeviceOrientationProvider:(id)arg0 ;
- (void)_setGeolocationProvider:(id)arg0 ;
- (id)_notificationProvider;
- (void)_setNotificationProvider:(id)arg0 ;
- (void)_notificationControllerDestroyed;
- (void)_notificationDidShow:(unsigned long long)arg0 ;
- (void)_notificationDidClick:(unsigned long long)arg0 ;
- (void)_notificationsDidClose:(id)arg0 ;
- (OpaqueJSValue)_computedStyleIncludingVisitedInfo:(OpaqueJSContext)arg0 forElement:(OpaqueJSValue)arg1 ;
- (char)acceptsFirstResponder;
- (void)_dispatchTileDidDraw:(id)arg0 ;
- (void)_willStartScrollingOrZooming;
- (void)_didFinishScrollingOrZooming;
- (char)becomeFirstResponder;
- (void)viewDidMoveToWindow;
- (void)setBackgroundColor:(CGColorRef)arg0 ;
- (char)isEditable;
- (char)isLoading;

@end