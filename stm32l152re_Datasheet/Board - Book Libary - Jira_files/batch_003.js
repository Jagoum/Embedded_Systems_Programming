;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/initFieldPickers.js' */
!function(r){var e=require("jira/util/events/types");JIRA.bind(e.NEW_CONTENT_ADDED,function(e,i,n){n!==JIRA.CONTENT_ADDED_REASON.panelRefreshed&&(r(".js-epic-picker",i).each(function(){var e=r(this),e=new JIRA.EpicPicker({element:e});r(document).trigger(JIRA.EpicPicker.READY_EVENT,e)}),r(".js-sprint-picker",i).each(function(){var e=r(this),e=new JIRA.SprintPicker({element:e});r(document).trigger(JIRA.SprintPicker.READY_EVENT,e)}))})}(AJS.$);;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/EpicPicker.js' */
!function(){"use strict";var e=require("jira/ajs/select/single-select");JIRA.EpicPicker=e.extend({init:function(r){var n,a=r.element,s=this;AJS.$.extend(r,{submitInputVal:!0,showDropdownButton:!0,removeDuplicates:!0,ajaxOptions:{url:contextPath+"/rest/agile/1.0/epic/search",query:!0,data:function(e){var r=!c();return{query:e,projectKey:AJS.$(a).attr("data-project-key"),maxResults:20,excludeDone:r}},formatResponse:function(e){if(!e||!e.values)return[];var a=s.getQueryVal(),o=new AJS.GroupDescriptor({weight:0,showLabel:!1,items:[new AJS.ItemDescriptor({label:a,highlighted:!0,styleClass:"ghx-epic-menu-header",customItem:!0,html:"<li><label for='chkShowDoneEpic'><input type='checkbox' id='chkShowDoneEpic'"+(c()?" checked":"")+">"+"Show done epics"+"</label></li>"})],replace:!0});return _.each(e.values,function(e){var r,t,i,n;o.addItem((t=a,i=(r=e).key,n=e.name,r=e.isDone,t=function(e,r,t,i){e=AJS.escapeHTML(String(e)),r=AJS.escapeHTML(String(r));var n,a=(i=AJS.escapeHTML(String(i))).toUpperCase(),o=e.toUpperCase(),s=r.toUpperCase(),a=(a+"").replace(/([\\\.\+\*\?\[\^\]\$\(\)\{\}\=\!\<\>\|\:])/g,"\\$1"),a=new RegExp("("+a+")","gi"),o=o.search(a);-1<o&&(n=e.slice(o,o+i.length),e=e.replace(n,"<em>"+n+"</em>"));-1<(o=s.search(a))&&(n=r.slice(o,o+i.length),r=r.replace(n,"<em>"+n+"</em>"));t=t?" &#8226; "+"Done":"";return e+" - <span class='epic-menu-metadata'>("+r+t+")</span>"}(n,i,r,t),new AJS.ItemDescriptor({value:"key:"+i,fieldText:n,label:t,html:t,allowDuplicate:!1,highlighted:!0})))}),[o]},error:function(e,r,t){var i=AJS.$(a);i.siblings(".ghx-error").remove(),i.before(GH.tpl.rapid.notification.renderAuiMessage({message:"Error"+": "+t,type:"error",className:"ghx-error aui-ss"}))}}});var t=this.setSelection;function i(e){var r,t,i;n.apply(s,[e]),e=e||AJS.$.trim(s.$field.val()),!s.model.getDescriptor(e)&&s.$container.hasClass("aui-ss-editing")&&(t="",i=!1,(r=e)&&0<r.length&&(t=AJS.format("Epic with key \'\'{0}\'\' does not exist.",r),i=!0),(t={isError:i,message:t}).isError?(s.options.errorMessage=t.message,s.showErrorMessage(e)):s.hideErrorMessage())}function c(){return"true"===localStorage.getItem("gh.epicpicker.showdone")}function o(e){e.preventDefault();e=!c();return localStorage.setItem("gh.epicpicker.showdone",e),s.$field.click(),!1}this.setSelection=function(e,r){e.properties.customItem||t.apply(this,arguments)},function(){s._super(r),n=s.handleFreeInput,s.handleFreeInput=i;var e=require("jira/ajs/layer/inline-layer");s.dropdownController.bind(e.EVENTS.show,function(e,r){r.off("click",'.ghx-epic-menu-header label[for="chkShowDoneEpic"]',o),r.on("click",'.ghx-epic-menu-header label[for="chkShowDoneEpic"]',o)})}()}}),JIRA.EpicPicker.READY_EVENT="gh.epic-picker.ready"}();;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/SprintPicker.js' */
JIRA.SprintPicker=AJS.SingleSelect.extend({init:function(e){var t,i,r,s={ACTIVE:"ACTIVE",FUTURE:"FUTURE",CLOSED:"CLOSED"},o=e.element,a=o.data("saved-state"),g=o.data("saved-id"),l=this,n=AJS.SelectSuggestHandler.extend({formatSuggestions:function(e,n){return e=this._super(e,n),0===n.length&&e[e.length-1].footerText("Start typing for sprints."),e}});function p(e){var n=t.apply(this,arguments);return n.find("a").append(GH.tpl.customfields.sprintpicker.renderSuggestionMeta(e.properties)),n}function d(e){var n=this.getSelectedDescriptor();e||n||h(null),r&&(r.remove(),r=null),this.hideErrorMessage(),(n=n?function(e){var n=!1;a===s.ACTIVE?n=!!f()||g!=e.properties.value:a!==s.FUTURE&&a||e.properties.stateKey===s.ACTIVE&&(n=!0);return{message:null,needsScopeChangeWarning:n}}(n):function(e){var n=null,t=!1;e&&0<e.length?a?(n=AJS.format("{0} is not a valid sprint name. This issue will be returned to the backlog.",e),a===s.ACTIVE&&(t=!0)):n=AJS.format("{0} is not a valid sprint name.",e):a===s.ACTIVE&&(t=!0);return{message:n,needsScopeChangeWarning:t}}(e)).message&&(this.options.errorMessage=n.message,i.apply(this,arguments),this.$errorMessage.addClass("inline-edit-error")),n.needsScopeChangeWarning&&function(){{var e;r||(f()||(r=AJS.$(GH.tpl.rapid.notification.renderAuiMessage({type:"warning",className:"ghx-sprint-picker-scope-warning",icon:!0,title:"Sprint scope will be affected by this action."}))),0<(e=l.$container.closest(".inline-edit-fields")).size()?f()?((r=AJS.$('<div class="ghx-estimate-scope-warning"></div>')).text("Sprint scope will be affected by this action."),0===e.find(".field-group .ghx-estimate-scope-warning").length&&e.find(".field-group").append(r)):0===e.find(".field-group .ghx-estimate-scope-warning").length&&e.closest(".editable-field").append(r):(f()&&(r=AJS.$(GH.tpl.rapid.notification.renderAuiMessage({type:"warning",className:"ghx-sprint-picker-scope-warning",icon:!0,title:"Sprint scope will be affected by this action."}))),0===l.$container.closest(".field-group .ghx-sprint-picker-scope-warning").length&&l.$container.closest(".field-group").append(r)))}r.show()}()}function c(e,n){var t=AJS.escapeHTML(String(e.name));return new AJS.ItemDescriptor({value:e.id.toString(),label:e.name,html:t,stateKey:e.stateKey,boardName:e.boardName,allowDuplicate:!1,isSuggestion:n})}function u(e){return _.sortBy(e,function(e){return e.name.toLowerCase()})}function h(e){GH.SprintConfig&&AJS.$(GH).trigger("QuickEdit.fieldChange",{fieldId:GH.SprintConfig.getSprintFieldId(),fieldChangeData:{original:g,updated:e?e.properties.value:null}})}function f(){return GH&&GH.DetailsView}AJS.$.extend(e,{submitInputVal:!1,showDropdownButton:!0,removeOnUnSelect:!1,maxInlineResultsDisplayed:10,ajaxOptions:{url:contextPath+"/rest/greenhopper/1.0/sprint/picker",query:!0,formatResponse:function(e){if(!e.suggestions&&!e.allMatches)return[];var n=new AJS.GroupDescriptor({weight:0,label:"Suggestions"}),t=new AJS.GroupDescriptor({weight:1,label:"All sprints"});return _.each(u(e.suggestions),function(e){n.addItem(c(e,!0))}),_.each(u(e.allMatches),function(e){t.addItem(c(e,!1))}),[n,t]},error:function(e,n,t){var r=AJS.$(o);r.siblings(".ghx-error").remove(),r.before(GH.tpl.rapid.notification.renderAuiMessage({message:"Error"+": "+t,type:"error",className:"ghx-error aui-ss"}))}}}),function(){{var r;l._super(e),t=l.listController._renders.suggestion,i=l.showErrorMessage,l.listController._renders.suggestion=p,l.showErrorMessage=d,f()&&(r=0<l.$container.closest(".inline-edit-fields").size())&&o.parent().find("input").on("focus",function(){l.showErrorMessage()})}o.bind("selected",function(e,n,t){f()&&r||t.showErrorMessage(t.getQueryVal()),h(n),l.showErrorMessage()}),l.suggestionsHandler=new n(l.options,l.model)}()}}),JIRA.SprintPicker.READY_EVENT="gh.sprint-picker.ready";;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/SprintPicker.soy' */
// This file was automatically generated from SprintPicker.soy.
// Please don't edit this file by hand.

/**
 * @fileoverview Templates in namespace GH.tpl.customfields.sprintpicker.
 */

if (typeof GH == 'undefined') { var GH = {}; }
if (typeof GH.tpl == 'undefined') { GH.tpl = {}; }
if (typeof GH.tpl.customfields == 'undefined') { GH.tpl.customfields = {}; }
if (typeof GH.tpl.customfields.sprintpicker == 'undefined') { GH.tpl.customfields.sprintpicker = {}; }


GH.tpl.customfields.sprintpicker.renderSuggestionMeta = function(opt_data, opt_ignored) {
  return '' + ((opt_data.boardName && ! opt_data.isSuggestion) ? '<span class=\'ghx-sprint-picker-meta\'> (' + GH.tpl.customfields.sprintpicker.renderMetaWithBoardName(opt_data) + ')</span>' : '<span class=\'ghx-sprint-picker-meta\'> (' + GH.tpl.customfields.sprintpicker.renderMetaWithoutBoardName(opt_data) + ')</span>');
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintpicker.renderSuggestionMeta.soyTemplateName = 'GH.tpl.customfields.sprintpicker.renderSuggestionMeta';
}


GH.tpl.customfields.sprintpicker.renderMetaWithoutBoardName = function(opt_data, opt_ignored) {
  return '' + ((opt_data.stateKey == 'ACTIVE') ? soy.$$escapeHtml('Active sprint') : (opt_data.stateKey == 'FUTURE') ? soy.$$escapeHtml('Future sprint') : '');
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintpicker.renderMetaWithoutBoardName.soyTemplateName = 'GH.tpl.customfields.sprintpicker.renderMetaWithoutBoardName';
}


GH.tpl.customfields.sprintpicker.renderMetaWithBoardName = function(opt_data, opt_ignored) {
  return '' + ((opt_data.stateKey == 'ACTIVE') ? soy.$$escapeHtml(AJS.format('Active sprint in {0}',opt_data.boardName)) : (opt_data.stateKey == 'FUTURE') ? soy.$$escapeHtml(AJS.format('Future sprint in {0}',opt_data.boardName)) : '');
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintpicker.renderMetaWithBoardName.soyTemplateName = 'GH.tpl.customfields.sprintpicker.renderMetaWithBoardName';
}
;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/rapid/ui/notification/Notification.js' */
!function(){function o(){return e(window).document}var e=require("jira/util/top-same-origin-window");AJS.namespace("GH.Notification"),GH.Notification.autoHideEnabled=!0;var t=Object.freeze({INFO:"info",SUCCESS:"success"});GH.Notification.showErrors=function(e,i){var t=GH.Notification.prepareNotificationDiv(),e=GH.tpl.rapid.notification.renderErrorMessages(e);void 0===i&&(i=!0),AJS.messages.error(t,{title:"Error",body:e,closeable:i}),GH.Notification._divStyle(t)&&t.css(GH.Notification._divStyle(t)),t.show()},GH.Notification.showError=function(e,i,t){var o=GH.Notification.prepareNotificationDiv();void 0===t&&(t=!0),AJS.messages.error(o,{title:e,body:i,closeable:t}),GH.Notification._divStyle(o)&&o.css(GH.Notification._divStyle(o)),o.show()},GH.Notification.showWarnings=function(e,i){i=_.extend({},{autoHide:!0,autoHideDelay:5e3,preRendered:!1,showTitle:!1},i);var t=GH.Notification.prepareNotificationDiv(),e=i.preRendered?e:GH.tpl.rapid.notification.renderErrorMessages({errors:e}),e={body:e,closeable:!0};i.showTitle&&(e.title="Warning"),AJS.messages.warning(t,e),GH.Notification._divStyle(t)&&t.css(GH.Notification._divStyle(t)),t.show(),i.autoHide&&GH.Notification.autoHideEnabled&&setTimeout(function(){t.hide()},i.autoHideDelay)},GH.Notification.showWarning=function(e){var i=GH.Notification.prepareNotificationDiv();AJS.messages.warning(i,{body:e,closeable:!0}),GH.Notification._divStyle(i)&&i.css(GH.Notification._divStyle(i)),i.show()},GH.Notification.clear=function(){GH.Notification.prepareNotificationDiv().hide()},GH.Notification.handleDateFormatMismatchError=function(e){var i='<a href="'+GH.Ajax.CONTEXT_PATH+'/secure/admin/AdvancedApplicationProperties.jspa">';i+="Advanced Settings",i+="</a>";i=AJS.format("It appears your Jira date format settings are misconfigured. Please check the {0} and ensure that \'\'jira.date.time.picker.java.format\'\' and \'\'jira.date.time.picker.javascript.format\'\' have matching output.",i);GH.Notification.showWarnings(i,{autoHide:!1,preRendered:!0})},GH.Notification.auiMessage=function(e){e=_.extend({type:"generic",icon:!0,messageHtml:!1},e);return GH.tpl.rapid.notification.renderAuiMessage({type:e.type,title:e.title,icon:e.icon,messageHtml:e.messageHtml,message:e.message})},GH.Notification.Handler={_defaultNotificationHandler:function(){var e=AJS.$("<div/>").addClass("global-msg");return AJS.$(".global-msg",o()).remove(),AJS.$("body",o()).append(e),e},_defaultDivStyleHandler:function(e){return{marginLeft:-e.outerWidth()/2,top:20}},setCustomDivStyleHandler:function(e){this._customDivStyleHandler=e,this._useDefault=!1},_useDefault:!0,setCustomNotificationHandler:function(e){this._customNotificationHandler=e,this._useDefault=!1},removeCustomHandlers:function(){this._useDefault=!0},getNotificationHandler:function(){return this._useDefault||null==this._customNotificationHandler?this._defaultNotificationHandler:this._customNotificationHandler},getDivStyleHandler:function(){return this._useDefault||null==this._customDivStyleHandler?this._defaultDivStyleHandler:this._customDivStyleHandler}},GH.Notification._divStyle=function(e){return GH.Notification.Handler.getDivStyleHandler()(e)},GH.Notification.prepareNotificationDiv=function(){return GH.Notification.Handler.getNotificationHandler()()},GH.Notification.showSuccess=function(e,i){a(t.SUCCESS,e,i)},GH.Notification.showInfo=function(e,i){a(t.INFO,e,i)};var a=function(e,i,t){clearTimeout(GH.Notification.current);t=_.extend({timeout:5e3,closeable:!0,shadowed:!0},t,{body:i});i=GH.Notification.prepareNotificationDiv();AJS.messages[e](i,t),GH.Notification._divStyle(i)&&i.css(GH.Notification._divStyle(i)),i.show(),GH.Notification.autoHideEnabled&&(GH.Notification.current=setTimeout(function(){AJS.$(".global-msg",o()).hide()},t.timeout))};GH.Notification.showIssueMessage=function(e){var i,t,o=JIRA.SessionStorage;(e=e||o.getItem("selectedIssueId"))&&(t=o.getItem("selectedIssueKey"),i=o.getItem("selectedIssueMsg"),GH.Notification.showIssueMessageImpl(e,i,t)),o.removeItem("selectedIssueId"),o.removeItem("selectedIssueKey"),o.removeItem("selectedIssueMsg")},GH.Notification.showIssueMessageImpl=function(e,i,t){i=i||"thanks_issue_updated";i=AJS.params[i];i&&t&&(i=AJS.format(i,t),GH.Notification.showSuccess(i))},GH.Notification.addPageLoadMessage=function(e,i){var t=GH.storage.get("gh.pageloadmessages",!0)||[];t.push({message:e,type:i||"success"}),GH.storage.put("gh.pageloadmessages",t,!0)},GH.Notification._displayPageLoadMessages=function(){var e,i,t=GH.storage.get("gh.pageloadmessages",!0);t&&(e=t[0].type,i="",_.each(t,function(e){0<i.length&&(i+="<br>"),i+=e.message}),"warning"===e?GH.Notification.showWarning(i):GH.Notification.showSuccess(i),GH.storage.put("gh.pageloadmessages",null,!0))};var n=null;GH.Notification.showBoardUpdatedMessage=function(){var e,i=AJS.$.Deferred();0===AJS.$(".aui-flag[aria-hidden=false]").length&&(e=GH.tpl.rapid.notification.renderGHtvMessage({showIgnore:!1}),n=AJS.flag({type:"info",body:e}),AJS.$(e));function t(e){e.preventDefault(),GH.Notification.clearBoardUpdatedMessage(),i.resolve()}return AJS.$(".js-refresh-now").off("click",t).click(t),i.promise()},GH.Notification.clearBoardUpdatedMessage=function(){n&&n.close()},GH.Notification.isBoardUpdatedMessageVisible=function(){return 0<AJS.$("#ghx-update-message").length},AJS.$(document).ready(function(){GH.Notification.showIssueMessage(),GH.storage&&GH.Notification._displayPageLoadMessages()})}();;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/rapid/ui/notification/Notification.soy' */
// This file was automatically generated from Notification.soy.
// Please don't edit this file by hand.

/**
 * @fileoverview Templates in namespace GH.tpl.rapid.notification.
 */

if (typeof GH == 'undefined') { var GH = {}; }
if (typeof GH.tpl == 'undefined') { GH.tpl = {}; }
if (typeof GH.tpl.rapid == 'undefined') { GH.tpl.rapid = {}; }
if (typeof GH.tpl.rapid.notification == 'undefined') { GH.tpl.rapid.notification = {}; }


GH.tpl.rapid.notification.renderErrorMessages = function(opt_data, opt_ignored) {
  var output = '';
  if (opt_data.errors.length > 1) {
    output += '<ul>';
    var errorList6 = opt_data.errors;
    var errorListLen6 = errorList6.length;
    for (var errorIndex6 = 0; errorIndex6 < errorListLen6; errorIndex6++) {
      var errorData6 = errorList6[errorIndex6];
      output += '<li>' + ((errorData6.noAutoescape) ? soy.$$filterNoAutoescape(errorData6.message) : soy.$$escapeHtml(errorData6.message)) + '</li>';
    }
    output += '</ul>';
  } else {
    var errorList18 = opt_data.errors;
    var errorListLen18 = errorList18.length;
    for (var errorIndex18 = 0; errorIndex18 < errorListLen18; errorIndex18++) {
      var errorData18 = errorList18[errorIndex18];
      output += '<p>' + ((errorData18.noAutoescape) ? soy.$$filterNoAutoescape(errorData18.message) : soy.$$escapeHtml(errorData18.message)) + '</p>';
    }
  }
  return output;
};
if (goog.DEBUG) {
  GH.tpl.rapid.notification.renderErrorMessages.soyTemplateName = 'GH.tpl.rapid.notification.renderErrorMessages';
}


GH.tpl.rapid.notification.renderContextualErrors = function(opt_data, opt_ignored) {
  var output = '';
  var errorList29 = opt_data.errors;
  var errorListLen29 = errorList29.length;
  for (var errorIndex29 = 0; errorIndex29 < errorListLen29; errorIndex29++) {
    var errorData29 = errorList29[errorIndex29];
    output += '<div class="ghx-error">' + soy.$$escapeHtml(errorData29.message) + '</div>';
  }
  return output;
};
if (goog.DEBUG) {
  GH.tpl.rapid.notification.renderContextualErrors.soyTemplateName = 'GH.tpl.rapid.notification.renderContextualErrors';
}


GH.tpl.rapid.notification.renderMessageHolder = function(opt_data, opt_ignored) {
  return '<div class="ghx-body-warning">' + soy.$$escapeHtml(AJS.format('This version of {0} is not a supported browser.',opt_data.browser)) + ' <a href="' + soy.$$escapeHtml(opt_data.docsUrl) + '">' + soy.$$escapeHtml('See our documentation for the list of supported browsers.') + '</a></div>';
};
if (goog.DEBUG) {
  GH.tpl.rapid.notification.renderMessageHolder.soyTemplateName = 'GH.tpl.rapid.notification.renderMessageHolder';
}


GH.tpl.rapid.notification.renderAuiMessage = function(opt_data, opt_ignored) {
  return '<div id="ghx-global-message" class="aui-message ' + soy.$$escapeHtml(opt_data.type) + ((opt_data.className) ? ' ' + soy.$$escapeHtml(opt_data.className) : '') + '">' + ((opt_data.title) ? '<p class="title">' + ((opt_data.icon) ? '<span class="aui-icon icon-' + soy.$$escapeHtml(opt_data.type) + '"></span>' : '') + '<strong>' + soy.$$escapeHtml(opt_data.title) + '</strong></p>' : '') + ((opt_data.message) ? '<p>' + ((! opt_data.title && opt_data.icon) ? '<span class="aui-icon icon-' + soy.$$escapeHtml(opt_data.type) + '"></span>' : '') + ((opt_data.messageHtml) ? soy.$$filterNoAutoescape(opt_data.message) : soy.$$escapeHtml(opt_data.message)) + '</p>' : '') + '</div>';
};
if (goog.DEBUG) {
  GH.tpl.rapid.notification.renderAuiMessage.soyTemplateName = 'GH.tpl.rapid.notification.renderAuiMessage';
}


GH.tpl.rapid.notification.renderGHtvMessage = function(opt_data, opt_ignored) {
  opt_data = opt_data || {};
  return '<div id="ghx-update-message" class="ghx-tv-message"><p>' + soy.$$escapeHtml('This board has been updated') + ': <a href="" class="js-refresh-now">' + soy.$$escapeHtml('Refresh') + '</a>' + ((opt_data.showIgnore) ? '<span class="ghx-divider">&bull;</span><a href="" class="js-ignore-refresh">' + soy.$$escapeHtml('Ignore') + '</a>' : '') + '</p></div>';
};
if (goog.DEBUG) {
  GH.tpl.rapid.notification.renderGHtvMessage.soyTemplateName = 'GH.tpl.rapid.notification.renderGHtvMessage';
}
;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/SprintMultiselect.js' */
!function(){"use strict";var e=require("jira/util/events/types");JIRA.bind(e.NEW_CONTENT_ADDED,function(e,t){function n(e){return[new AJS.GroupDescriptor({weight:0,label:"Suggestions",items:_.map(e.suggestions,s)}),new AJS.GroupDescriptor({weight:1,label:"All sprints",items:_.map(e.allMatches,s)})]}function s(e){e.date=moment(e.date,"YYYY-MM-DDTHH:mm:ssZ").format("LL");var t=GH.tpl.customfields.sprintmultiselect.renderSuggestionMeta(e);return new AJS.ItemDescriptor({value:e.id,label:e.name,html:t,title:GH.tpl.customfields.sprintmultiselect.renderTooltip(e),date:e.date,boardName:e.boardName,stateKey:e.stateKey,highlighted:!0,allowDuplicate:!1})}AJS.$(".js-sprint-checkboxmultiselect",t).each(function(){var e=new AJS.CheckboxMultiSelect({element:this,maxInlineResultsDisplayed:5,content:"ajax",removeOnUnSelect:!0,ajaxOptions:{url:AJS.contextPath()+"/rest/greenhopper/1.0/sprint/picker",error:function(){e._setSuggestions([])},data:{excludeCompleted:!1},query:!0,formatResponse:n},suggestionsHandler:GH.SprintSuggestHandler})})})}();;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/SprintMultiselect.soy' */
// This file was automatically generated from SprintMultiselect.soy.
// Please don't edit this file by hand.

/**
 * @fileoverview Templates in namespace GH.tpl.customfields.sprintmultiselect.
 */

if (typeof GH == 'undefined') { var GH = {}; }
if (typeof GH.tpl == 'undefined') { GH.tpl = {}; }
if (typeof GH.tpl.customfields == 'undefined') { GH.tpl.customfields = {}; }
if (typeof GH.tpl.customfields.sprintmultiselect == 'undefined') { GH.tpl.customfields.sprintmultiselect = {}; }


GH.tpl.customfields.sprintmultiselect.renderSuggestionMeta = function(opt_data, opt_ignored) {
  return '<div>' + soy.$$escapeHtml(opt_data.name) + '</div><div><span class=\'ghx-sprint-multiselect-meta\'> ' + ((opt_data.boardName) ? GH.tpl.customfields.sprintmultiselect.renderMetaWithBoardName(opt_data) : GH.tpl.customfields.sprintmultiselect.renderMetaWithoutBoardName(opt_data)) + '</span></div>';
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintmultiselect.renderSuggestionMeta.soyTemplateName = 'GH.tpl.customfields.sprintmultiselect.renderSuggestionMeta';
}


GH.tpl.customfields.sprintmultiselect.renderMetaWithoutBoardName = function(opt_data, opt_ignored) {
  return '' + ((opt_data.stateKey == 'ACTIVE') ? soy.$$escapeHtml('Active') : (opt_data.stateKey == 'FUTURE') ? soy.$$escapeHtml('Future') : (opt_data.stateKey == 'CLOSED') ? soy.$$escapeHtml('Closed') : '');
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintmultiselect.renderMetaWithoutBoardName.soyTemplateName = 'GH.tpl.customfields.sprintmultiselect.renderMetaWithoutBoardName';
}


GH.tpl.customfields.sprintmultiselect.renderMetaWithBoardName = function(opt_data, opt_ignored) {
  return '' + ((opt_data.stateKey == 'ACTIVE') ? soy.$$escapeHtml(AJS.format('Active \xb7 {0}',opt_data.boardName)) : (opt_data.stateKey == 'FUTURE') ? soy.$$escapeHtml(AJS.format('Future \xb7 {0}',opt_data.boardName)) : (opt_data.stateKey == 'CLOSED') ? soy.$$escapeHtml(AJS.format('Closed \xb7 {0}',opt_data.boardName)) : '');
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintmultiselect.renderMetaWithBoardName.soyTemplateName = 'GH.tpl.customfields.sprintmultiselect.renderMetaWithBoardName';
}


GH.tpl.customfields.sprintmultiselect.renderTooltip = function(opt_data, opt_ignored) {
  return '' + ((opt_data.stateKey == 'ACTIVE') ? soy.$$escapeHtml(AJS.format('Started on {0}',opt_data.date)) : (opt_data.stateKey == 'FUTURE') ? soy.$$escapeHtml('Future') : (opt_data.stateKey == 'CLOSED') ? soy.$$escapeHtml(AJS.format('Closed on {0}',opt_data.date)) : '');
};
if (goog.DEBUG) {
  GH.tpl.customfields.sprintmultiselect.renderTooltip.soyTemplateName = 'GH.tpl.customfields.sprintmultiselect.renderTooltip';
}
;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/SprintSuggestHandler.js' */
function prepareSelectedDescriptors(e){_.each(e,function(e){var t=JSON.parse(e.properties.meta);t.date=moment(t.date).format("LL"),e.properties.title=GH.tpl.customfields.sprintmultiselect.renderTooltip(t),e.properties.html=GH.tpl.customfields.sprintmultiselect.renderSuggestionMeta(t)})}define("includes/js/field/sprint-suggest-handler",["jira/ajs/select/suggestions/checkbox-multi-select-suggest-handler"],function(e){return e.extend({formatSuggestions:function(e,t){var r=this.model.getDisplayableSelectedDescriptors();prepareSelectedDescriptors(r);function s(e){for(var t in r)if(r[t].properties.value===e.properties.value.toString())return!1;return!0}return e=_.map(e,function(e){var t=_.filter(e.properties.items,s);return e.properties.items=t,e}),this._super(e,t)}})}),AJS.namespace("GH.SprintSuggestHandler",null,require("includes/js/field/sprint-suggest-handler"));;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/EpicLinkMultiselect.js' */
require(["require"],function(e){var n=e("jquery"),c=e("underscore"),e=e("jira/util/events/types");function r(e){return 0!==e.indexOf("project")?"":(function(e){return(e=e.match(/\bproject\s*=\s*(\S+)/i))?e[1]:null}(e=e)||function(e){return(e=e.match(/\bproject\s+in\s+\((.*?)\)/i))?e[1]:null}(e)).trim()}JIRA.bind(e.NEW_CONTENT_ADDED,function(e,t){var i=n("#jql",this).val();t.find(".js-epiclink-checkboxmultiselect").each(function(){var e=new AJS.CheckboxMultiSelect({element:this,matchingStrategy:"(^|.*?(.*))({0})(.*)",maxInlineResultsDisplayed:5,content:"ajax",removeOnUnSelect:!0,ajaxOptions:{url:AJS.contextPath()+"/rest/greenhopper/1.0/epics",error:function(){e._setSuggestions([])},data:{searchQuery:"",projectKey:r(i),filterEpicsByGivenProjects:!0,maxResults:100},query:!0,minQueryLength:0,formatResponse:function(e){var t=[];if(t.push(new AJS.GroupDescriptor({weight:1,items:[new AJS.ItemDescriptor({highlighted:!0,label:"No Epic Link",value:"EMPTY",title:"EMPTY"})]})),!e||!e.epicLists||0===e.total)return t;for(var i=0;i<e.epicLists.length;i++){var n=e.epicLists[i],r=n.epicNames,s=new AJS.GroupDescriptor({label:n.listDescriptor,weight:i});0<r.length&&(c.each(r,function(e){s.addItem(new AJS.ItemDescriptor({highlighted:!0,label:e.name+" - ("+e.key+")",value:e.key,title:e.key}))}),t.push(s))}return t}},suggestionsHandler:GH.EpicLinkSuggestHandler})})})});;
;
/* module-key = 'com.pyxis.greenhopper.jira:gh-custom-field-pickers', location = 'jira-agile-module/includes/js/field/EpicLinkSuggestHandler.js' */
define("includes/js/field/epic-link-suggest-handler",["jira/ajs/select/suggestions/checkbox-multi-select-suggest-handler"],function(e){return e.extend({formatSuggestions:function(e,r){function i(e){for(var r in t)if(t[r].properties.value===e.properties.value.toString())return!1;return!0}var t=this.model.getDisplayableSelectedDescriptors();return e=_.map(e,function(e){var r=_.filter(e.properties.items,i);return e.properties.items=r,e}),this._super(e,r)}})}),AJS.namespace("GH.EpicLinkSuggestHandler",null,require("includes/js/field/epic-link-suggest-handler"));;