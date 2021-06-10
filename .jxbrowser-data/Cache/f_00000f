(function(){/*

 Copyright The Closure Library Authors.
 SPDX-License-Identifier: Apache-2.0
*/
'use strict';var m;function aa(a){var b=0;return function(){return b<a.length?{done:!1,value:a[b++]}:{done:!0}}}
var ca="function"==typeof Object.defineProperties?Object.defineProperty:function(a,b,c){if(a==Array.prototype||a==Object.prototype)return a;a[b]=c.value;return a};
function da(a){a=["object"==typeof globalThis&&globalThis,a,"object"==typeof window&&window,"object"==typeof self&&self,"object"==typeof global&&global];for(var b=0;b<a.length;++b){var c=a[b];if(c&&c.Math==Math)return c}throw Error("Cannot find global object");}
var ea=da(this);function t(a,b){if(b)a:{var c=ea;a=a.split(".");for(var d=0;d<a.length-1;d++){var e=a[d];if(!(e in c))break a;c=c[e]}a=a[a.length-1];d=c[a];b=b(d);b!=d&&null!=b&&ca(c,a,{configurable:!0,writable:!0,value:b})}}
t("Symbol",function(a){function b(e){if(this instanceof b)throw new TypeError("Symbol is not a constructor");return new c("jscomp_symbol_"+(e||"")+"_"+d++,e)}
function c(e,f){this.h=e;ca(this,"description",{configurable:!0,writable:!0,value:f})}
if(a)return a;c.prototype.toString=function(){return this.h};
var d=0;return b});
t("Symbol.iterator",function(a){if(a)return a;a=Symbol("Symbol.iterator");for(var b="Array Int8Array Uint8Array Uint8ClampedArray Int16Array Uint16Array Int32Array Uint32Array Float32Array Float64Array".split(" "),c=0;c<b.length;c++){var d=ea[b[c]];"function"===typeof d&&"function"!=typeof d.prototype[a]&&ca(d.prototype,a,{configurable:!0,writable:!0,value:function(){return fa(aa(this))}})}return a});
function fa(a){a={next:a};a[Symbol.iterator]=function(){return this};
return a}
function u(a){var b="undefined"!=typeof Symbol&&Symbol.iterator&&a[Symbol.iterator];return b?b.call(a):{next:aa(a)}}
function ha(a){for(var b,c=[];!(b=a.next()).done;)c.push(b.value);return c}
var ia="function"==typeof Object.create?Object.create:function(a){function b(){}
b.prototype=a;return new b},ja=function(){function a(){function c(){}
new c;Reflect.construct(c,[],function(){});
return new c instanceof c}
if("undefined"!=typeof Reflect&&Reflect.construct){if(a())return Reflect.construct;var b=Reflect.construct;return function(c,d,e){c=b(c,d);e&&Reflect.setPrototypeOf(c,e.prototype);return c}}return function(c,d,e){void 0===e&&(e=c);
e=ia(e.prototype||Object.prototype);return Function.prototype.apply.call(c,e,d)||e}}(),ka;
if("function"==typeof Object.setPrototypeOf)ka=Object.setPrototypeOf;else{var la;a:{var ma={a:!0},na={};try{na.__proto__=ma;la=na.a;break a}catch(a){}la=!1}ka=la?function(a,b){a.__proto__=b;if(a.__proto__!==b)throw new TypeError(a+" is not extensible");return a}:null}var pa=ka;
function v(a,b){a.prototype=ia(b.prototype);a.prototype.constructor=a;if(pa)pa(a,b);else for(var c in b)if("prototype"!=c)if(Object.defineProperties){var d=Object.getOwnPropertyDescriptor(b,c);d&&Object.defineProperty(a,c,d)}else a[c]=b[c];a.M=b.prototype}
function qa(){this.o=!1;this.l=null;this.i=void 0;this.h=1;this.u=this.m=0;this.C=this.j=null}
function ra(a){if(a.o)throw new TypeError("Generator is already running");a.o=!0}
qa.prototype.B=function(a){this.i=a};
function sa(a,b){a.j={xa:b,ya:!0};a.h=a.m||a.u}
qa.prototype.return=function(a){this.j={return:a};this.h=this.u};
function w(a,b,c){a.h=c;return{value:b}}
qa.prototype.A=function(a){this.h=a};
function ta(a,b,c){a.m=b;void 0!=c&&(a.u=c)}
function ua(a){a.m=0;var b=a.j.xa;a.j=null;return b}
function va(a){a.C=[a.j];a.m=0;a.u=0}
function wa(a){var b=a.C.splice(0)[0];(b=a.j=a.j||b)?b.ya?a.h=a.m||a.u:void 0!=b.A&&a.u<b.A?(a.h=b.A,a.j=null):a.h=a.u:a.h=0}
function xa(a){this.h=new qa;this.i=a}
function ya(a,b){ra(a.h);var c=a.h.l;if(c)return za(a,"return"in c?c["return"]:function(d){return{value:d,done:!0}},b,a.h.return);
a.h.return(b);return Aa(a)}
function za(a,b,c,d){try{var e=b.call(a.h.l,c);if(!(e instanceof Object))throw new TypeError("Iterator result "+e+" is not an object");if(!e.done)return a.h.o=!1,e;var f=e.value}catch(g){return a.h.l=null,sa(a.h,g),Aa(a)}a.h.l=null;d.call(a.h,f);return Aa(a)}
function Aa(a){for(;a.h.h;)try{var b=a.i(a.h);if(b)return a.h.o=!1,{value:b.value,done:!1}}catch(c){a.h.i=void 0,sa(a.h,c)}a.h.o=!1;if(a.h.j){b=a.h.j;a.h.j=null;if(b.ya)throw b.xa;return{value:b.return,done:!0}}return{value:void 0,done:!0}}
function Ba(a){this.next=function(b){ra(a.h);a.h.l?b=za(a,a.h.l.next,b,a.h.B):(a.h.B(b),b=Aa(a));return b};
this.throw=function(b){ra(a.h);a.h.l?b=za(a,a.h.l["throw"],b,a.h.B):(sa(a.h,b),b=Aa(a));return b};
this.return=function(b){return ya(a,b)};
this[Symbol.iterator]=function(){return this}}
function x(a,b){b=new Ba(new xa(b));pa&&a.prototype&&pa(b,a.prototype);return b}
t("Reflect",function(a){return a?a:{}});
t("Reflect.construct",function(){return ja});
t("Reflect.setPrototypeOf",function(a){return a?a:pa?function(b,c){try{return pa(b,c),!0}catch(d){return!1}}:null});
function Ca(a,b,c){if(null==a)throw new TypeError("The 'this' value for String.prototype."+c+" must not be null or undefined");if(b instanceof RegExp)throw new TypeError("First argument to String.prototype."+c+" must not be a regular expression");return a+""}
t("String.prototype.endsWith",function(a){return a?a:function(b,c){var d=Ca(this,b,"endsWith");b+="";void 0===c&&(c=d.length);c=Math.max(0,Math.min(c|0,d.length));for(var e=b.length;0<e&&0<c;)if(d[--c]!=b[--e])return!1;return 0>=e}});
t("String.prototype.startsWith",function(a){return a?a:function(b,c){var d=Ca(this,b,"startsWith");b+="";var e=d.length,f=b.length;c=Math.max(0,Math.min(c|0,d.length));for(var g=0;g<f&&c<e;)if(d[c++]!=b[g++])return!1;return g>=f}});
t("Object.setPrototypeOf",function(a){return a||pa});
function Da(a,b){return Object.prototype.hasOwnProperty.call(a,b)}
var Ea="function"==typeof Object.assign?Object.assign:function(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(d)for(var e in d)Da(d,e)&&(a[e]=d[e])}return a};
t("Object.assign",function(a){return a||Ea});
t("Promise",function(a){function b(g){this.h=0;this.j=void 0;this.i=[];this.o=!1;var h=this.l();try{g(h.resolve,h.reject)}catch(k){h.reject(k)}}
function c(){this.h=null}
function d(g){return g instanceof b?g:new b(function(h){h(g)})}
if(a)return a;c.prototype.i=function(g){if(null==this.h){this.h=[];var h=this;this.j(function(){h.u()})}this.h.push(g)};
var e=ea.setTimeout;c.prototype.j=function(g){e(g,0)};
c.prototype.u=function(){for(;this.h&&this.h.length;){var g=this.h;this.h=[];for(var h=0;h<g.length;++h){var k=g[h];g[h]=null;try{k()}catch(l){this.l(l)}}}this.h=null};
c.prototype.l=function(g){this.j(function(){throw g;})};
b.prototype.l=function(){function g(l){return function(p){k||(k=!0,l.call(h,p))}}
var h=this,k=!1;return{resolve:g(this.K),reject:g(this.u)}};
b.prototype.K=function(g){if(g===this)this.u(new TypeError("A Promise cannot resolve to itself"));else if(g instanceof b)this.N(g);else{a:switch(typeof g){case "object":var h=null!=g;break a;case "function":h=!0;break a;default:h=!1}h?this.J(g):this.m(g)}};
b.prototype.J=function(g){var h=void 0;try{h=g.then}catch(k){this.u(k);return}"function"==typeof h?this.V(h,g):this.m(g)};
b.prototype.u=function(g){this.B(2,g)};
b.prototype.m=function(g){this.B(1,g)};
b.prototype.B=function(g,h){if(0!=this.h)throw Error("Cannot settle("+g+", "+h+"): Promise already settled in state"+this.h);this.h=g;this.j=h;2===this.h&&this.L();this.C()};
b.prototype.L=function(){var g=this;e(function(){if(g.F()){var h=ea.console;"undefined"!==typeof h&&h.error(g.j)}},1)};
b.prototype.F=function(){if(this.o)return!1;var g=ea.CustomEvent,h=ea.Event,k=ea.dispatchEvent;if("undefined"===typeof k)return!0;"function"===typeof g?g=new g("unhandledrejection",{cancelable:!0}):"function"===typeof h?g=new h("unhandledrejection",{cancelable:!0}):(g=ea.document.createEvent("CustomEvent"),g.initCustomEvent("unhandledrejection",!1,!0,g));g.promise=this;g.reason=this.j;return k(g)};
b.prototype.C=function(){if(null!=this.i){for(var g=0;g<this.i.length;++g)f.i(this.i[g]);this.i=null}};
var f=new c;b.prototype.N=function(g){var h=this.l();g.da(h.resolve,h.reject)};
b.prototype.V=function(g,h){var k=this.l();try{g.call(h,k.resolve,k.reject)}catch(l){k.reject(l)}};
b.prototype.then=function(g,h){function k(r,q){return"function"==typeof r?function(D){try{l(r(D))}catch(I){p(I)}}:q}
var l,p,n=new b(function(r,q){l=r;p=q});
this.da(k(g,l),k(h,p));return n};
b.prototype.catch=function(g){return this.then(void 0,g)};
b.prototype.da=function(g,h){function k(){switch(l.h){case 1:g(l.j);break;case 2:h(l.j);break;default:throw Error("Unexpected state: "+l.h);}}
var l=this;null==this.i?f.i(k):this.i.push(k);this.o=!0};
b.resolve=d;b.reject=function(g){return new b(function(h,k){k(g)})};
b.race=function(g){return new b(function(h,k){for(var l=u(g),p=l.next();!p.done;p=l.next())d(p.value).da(h,k)})};
b.all=function(g){var h=u(g),k=h.next();return k.done?d([]):new b(function(l,p){function n(D){return function(I){r[D]=I;q--;0==q&&l(r)}}
var r=[],q=0;do r.push(void 0),q++,d(k.value).da(n(r.length-1),p),k=h.next();while(!k.done)})};
return b});
t("Object.is",function(a){return a?a:function(b,c){return b===c?0!==b||1/b===1/c:b!==b&&c!==c}});
t("Array.prototype.includes",function(a){return a?a:function(b,c){var d=this;d instanceof String&&(d=String(d));var e=d.length;c=c||0;for(0>c&&(c=Math.max(c+e,0));c<e;c++){var f=d[c];if(f===b||Object.is(f,b))return!0}return!1}});
t("String.prototype.includes",function(a){return a?a:function(b,c){return-1!==Ca(this,b,"includes").indexOf(b,c||0)}});
t("Object.entries",function(a){return a?a:function(b){var c=[],d;for(d in b)Da(b,d)&&c.push([d,b[d]]);return c}});
t("WeakMap",function(a){function b(k){this.h=(h+=Math.random()+1).toString();if(k){k=u(k);for(var l;!(l=k.next()).done;)l=l.value,this.set(l[0],l[1])}}
function c(){}
function d(k){var l=typeof k;return"object"===l&&null!==k||"function"===l}
function e(k){if(!Da(k,g)){var l=new c;ca(k,g,{value:l})}}
function f(k){var l=Object[k];l&&(Object[k]=function(p){if(p instanceof c)return p;Object.isExtensible(p)&&e(p);return l(p)})}
if(function(){if(!a||!Object.seal)return!1;try{var k=Object.seal({}),l=Object.seal({}),p=new a([[k,2],[l,3]]);if(2!=p.get(k)||3!=p.get(l))return!1;p.delete(k);p.set(l,4);return!p.has(k)&&4==p.get(l)}catch(n){return!1}}())return a;
var g="$jscomp_hidden_"+Math.random();f("freeze");f("preventExtensions");f("seal");var h=0;b.prototype.set=function(k,l){if(!d(k))throw Error("Invalid WeakMap key");e(k);if(!Da(k,g))throw Error("WeakMap key fail: "+k);k[g][this.h]=l;return this};
b.prototype.get=function(k){return d(k)&&Da(k,g)?k[g][this.h]:void 0};
b.prototype.has=function(k){return d(k)&&Da(k,g)&&Da(k[g],this.h)};
b.prototype.delete=function(k){return d(k)&&Da(k,g)&&Da(k[g],this.h)?delete k[g][this.h]:!1};
return b});
t("Map",function(a){function b(){var h={};return h.previous=h.next=h.head=h}
function c(h,k){var l=h.h;return fa(function(){if(l){for(;l.head!=h.h;)l=l.previous;for(;l.next!=l.head;)return l=l.next,{done:!1,value:k(l)};l=null}return{done:!0,value:void 0}})}
function d(h,k){var l=k&&typeof k;"object"==l||"function"==l?f.has(k)?l=f.get(k):(l=""+ ++g,f.set(k,l)):l="p_"+k;var p=h.i[l];if(p&&Da(h.i,l))for(h=0;h<p.length;h++){var n=p[h];if(k!==k&&n.key!==n.key||k===n.key)return{id:l,list:p,index:h,H:n}}return{id:l,list:p,index:-1,H:void 0}}
function e(h){this.i={};this.h=b();this.size=0;if(h){h=u(h);for(var k;!(k=h.next()).done;)k=k.value,this.set(k[0],k[1])}}
if(function(){if(!a||"function"!=typeof a||!a.prototype.entries||"function"!=typeof Object.seal)return!1;try{var h=Object.seal({x:4}),k=new a(u([[h,"s"]]));if("s"!=k.get(h)||1!=k.size||k.get({x:4})||k.set({x:4},"t")!=k||2!=k.size)return!1;var l=k.entries(),p=l.next();if(p.done||p.value[0]!=h||"s"!=p.value[1])return!1;p=l.next();return p.done||4!=p.value[0].x||"t"!=p.value[1]||!l.next().done?!1:!0}catch(n){return!1}}())return a;
var f=new WeakMap;e.prototype.set=function(h,k){h=0===h?0:h;var l=d(this,h);l.list||(l.list=this.i[l.id]=[]);l.H?l.H.value=k:(l.H={next:this.h,previous:this.h.previous,head:this.h,key:h,value:k},l.list.push(l.H),this.h.previous.next=l.H,this.h.previous=l.H,this.size++);return this};
e.prototype.delete=function(h){h=d(this,h);return h.H&&h.list?(h.list.splice(h.index,1),h.list.length||delete this.i[h.id],h.H.previous.next=h.H.next,h.H.next.previous=h.H.previous,h.H.head=null,this.size--,!0):!1};
e.prototype.clear=function(){this.i={};this.h=this.h.previous=b();this.size=0};
e.prototype.has=function(h){return!!d(this,h).H};
e.prototype.get=function(h){return(h=d(this,h).H)&&h.value};
e.prototype.entries=function(){return c(this,function(h){return[h.key,h.value]})};
e.prototype.keys=function(){return c(this,function(h){return h.key})};
e.prototype.values=function(){return c(this,function(h){return h.value})};
e.prototype.forEach=function(h,k){for(var l=this.entries(),p;!(p=l.next()).done;)p=p.value,h.call(k,p[1],p[0],this)};
e.prototype[Symbol.iterator]=e.prototype.entries;var g=0;return e});
t("Set",function(a){function b(c){this.h=new Map;if(c){c=u(c);for(var d;!(d=c.next()).done;)this.add(d.value)}this.size=this.h.size}
if(function(){if(!a||"function"!=typeof a||!a.prototype.entries||"function"!=typeof Object.seal)return!1;try{var c=Object.seal({x:4}),d=new a(u([c]));if(!d.has(c)||1!=d.size||d.add(c)!=d||1!=d.size||d.add({x:4})!=d||2!=d.size)return!1;var e=d.entries(),f=e.next();if(f.done||f.value[0]!=c||f.value[1]!=c)return!1;f=e.next();return f.done||f.value[0]==c||4!=f.value[0].x||f.value[1]!=f.value[0]?!1:e.next().done}catch(g){return!1}}())return a;
b.prototype.add=function(c){c=0===c?0:c;this.h.set(c,c);this.size=this.h.size;return this};
b.prototype.delete=function(c){c=this.h.delete(c);this.size=this.h.size;return c};
b.prototype.clear=function(){this.h.clear();this.size=0};
b.prototype.has=function(c){return this.h.has(c)};
b.prototype.entries=function(){return this.h.entries()};
b.prototype.values=function(){return this.h.values()};
b.prototype.keys=b.prototype.values;b.prototype[Symbol.iterator]=b.prototype.values;b.prototype.forEach=function(c,d){var e=this;this.h.forEach(function(f){return c.call(d,f,f,e)})};
return b});
function Fa(a,b){a instanceof String&&(a+="");var c=0,d=!1,e={next:function(){if(!d&&c<a.length){var f=c++;return{value:b(f,a[f]),done:!1}}d=!0;return{done:!0,value:void 0}}};
e[Symbol.iterator]=function(){return e};
return e}
t("Array.prototype.entries",function(a){return a?a:function(){return Fa(this,function(b,c){return[b,c]})}});
t("Array.prototype.keys",function(a){return a?a:function(){return Fa(this,function(b){return b})}});
t("Array.prototype.values",function(a){return a?a:function(){return Fa(this,function(b,c){return c})}});
t("Number.isNaN",function(a){return a?a:function(b){return"number"===typeof b&&isNaN(b)}});
t("Number.MAX_SAFE_INTEGER",function(){return 9007199254740991});
t("Object.values",function(a){return a?a:function(b){var c=[],d;for(d in b)Da(b,d)&&c.push(b[d]);return c}});
var y=this||self;function z(a,b,c){a=a.split(".");c=c||y;a[0]in c||"undefined"==typeof c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c[d]&&c[d]!==Object.prototype[d]?c=c[d]:c=c[d]={}:c[d]=b}
function Ga(a){if(a&&a!=y)return Ha(a.document);null===Ia&&(Ia=Ha(y.document));return Ia}
var Ja=/^[\w+/_-]+[=]{0,2}$/,Ia=null;function Ha(a){return(a=a.querySelector&&a.querySelector("script[nonce]"))&&(a=a.nonce||a.getAttribute("nonce"))&&Ja.test(a)?a:""}
function A(a,b){a=a.split(".");b=b||y;for(var c=0;c<a.length;c++)if(b=b[a[c]],null==b)return null;return b}
function Ka(){}
function La(a){a.na=void 0;a.getInstance=function(){return a.na?a.na:a.na=new a}}
function Ma(a){var b=typeof a;return"object"!=b?b:a?Array.isArray(a)?"array":b:"null"}
function Na(a){var b=Ma(a);return"array"==b||"object"==b&&"number"==typeof a.length}
function Oa(a){var b=typeof a;return"object"==b&&null!=a||"function"==b}
function Pa(a){return Object.prototype.hasOwnProperty.call(a,Qa)&&a[Qa]||(a[Qa]=++Ra)}
var Qa="closure_uid_"+(1E9*Math.random()>>>0),Ra=0;function Sa(a,b,c){return a.call.apply(a.bind,arguments)}
function Ta(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var e=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(e,d);return a.apply(b,e)}}return function(){return a.apply(b,arguments)}}
function B(a,b,c){Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?B=Sa:B=Ta;return B.apply(null,arguments)}
function Ua(a,b){var c=Array.prototype.slice.call(arguments,1);return function(){var d=c.slice();d.push.apply(d,arguments);return a.apply(this,d)}}
function Va(a,b){z(a,b,void 0)}
function C(a,b){function c(){}
c.prototype=b.prototype;a.M=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.Ik=function(d,e,f){for(var g=Array(arguments.length-2),h=2;h<arguments.length;h++)g[h-2]=arguments[h];return b.prototype[e].apply(d,g)}}
function Wa(a){return a}
;function Xa(a,b){if(Error.captureStackTrace)Error.captureStackTrace(this,Xa);else{var c=Error().stack;c&&(this.stack=c)}a&&(this.message=String(a));b&&(this.Ja=b)}
C(Xa,Error);Xa.prototype.name="CustomError";function Ya(a){a=a.url;var b=/[?&]dsh=1(&|$)/.test(a);this.j=!b&&/[?&]ae=1(&|$)/.test(a);this.l=!b&&/[?&]ae=2(&|$)/.test(a);if((this.h=/[?&]adurl=([^&]*)/.exec(a))&&this.h[1]){try{var c=decodeURIComponent(this.h[1])}catch(d){c=null}this.i=c}}
;function Za(a){var b=!1,c;return function(){b||(c=a(),b=!0);return c}}
;var $a=Array.prototype.indexOf?function(a,b){return Array.prototype.indexOf.call(a,b,void 0)}:function(a,b){if("string"===typeof a)return"string"!==typeof b||1!=b.length?-1:a.indexOf(b,0);
for(var c=0;c<a.length;c++)if(c in a&&a[c]===b)return c;return-1},E=Array.prototype.forEach?function(a,b,c){Array.prototype.forEach.call(a,b,c)}:function(a,b,c){for(var d=a.length,e="string"===typeof a?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)},ab=Array.prototype.filter?function(a,b){return Array.prototype.filter.call(a,b,void 0)}:function(a,b){for(var c=a.length,d=[],e=0,f="string"===typeof a?a.split(""):a,g=0;g<c;g++)if(g in f){var h=f[g];
b.call(void 0,h,g,a)&&(d[e++]=h)}return d},bb=Array.prototype.map?function(a,b){return Array.prototype.map.call(a,b,void 0)}:function(a,b){for(var c=a.length,d=Array(c),e="string"===typeof a?a.split(""):a,f=0;f<c;f++)f in e&&(d[f]=b.call(void 0,e[f],f,a));
return d},cb=Array.prototype.reduce?function(a,b,c){return Array.prototype.reduce.call(a,b,c)}:function(a,b,c){var d=c;
E(a,function(e,f){d=b.call(void 0,d,e,f,a)});
return d};
function db(a,b){a:{for(var c=a.length,d="string"===typeof a?a.split(""):a,e=0;e<c;e++)if(e in d&&b.call(void 0,d[e],e,a)){b=e;break a}b=-1}return 0>b?null:"string"===typeof a?a.charAt(b):a[b]}
function eb(a,b){b=$a(a,b);var c;(c=0<=b)&&Array.prototype.splice.call(a,b,1);return c}
function fb(a){var b=a.length;if(0<b){for(var c=Array(b),d=0;d<b;d++)c[d]=a[d];return c}return[]}
function gb(a,b){for(var c=1;c<arguments.length;c++){var d=arguments[c];if(Na(d)){var e=a.length||0,f=d.length||0;a.length=e+f;for(var g=0;g<f;g++)a[e+g]=d[g]}else a.push(d)}}
;function hb(a,b){for(var c in a)b.call(void 0,a[c],c,a)}
function ib(a){var b=jb,c;for(c in b)if(a.call(void 0,b[c],c,b))return c}
function kb(a){for(var b in a)return!1;return!0}
function lb(a,b){if(null!==a&&b in a)throw Error('The object already contains the key "'+b+'"');a[b]=!0}
function nb(){var a=F("PLAYER_VARS",{});return null!==a&&"privembed"in a?a.privembed:!1}
function ob(a,b){for(var c in a)if(!(c in b)||a[c]!==b[c])return!1;for(var d in b)if(!(d in a))return!1;return!0}
function pb(a){var b={},c;for(c in a)b[c]=a[c];return b}
function qb(a){if(!a||"object"!==typeof a)return a;if("function"===typeof a.clone)return a.clone();var b=Array.isArray(a)?[]:"function"!==typeof ArrayBuffer||"function"!==typeof ArrayBuffer.isView||!ArrayBuffer.isView(a)||a instanceof DataView?{}:new a.constructor(a.length),c;for(c in a)b[c]=qb(a[c]);return b}
var rb="constructor hasOwnProperty isPrototypeOf propertyIsEnumerable toLocaleString toString valueOf".split(" ");function sb(a,b){for(var c,d,e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(var f=0;f<rb.length;f++)c=rb[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}}
;var tb;function ub(){if(void 0===tb){var a=null,b=y.trustedTypes;if(b&&b.createPolicy){try{a=b.createPolicy("goog#html",{createHTML:Wa,createScript:Wa,createScriptURL:Wa})}catch(c){y.console&&y.console.error(c.message)}tb=a}else tb=a}return tb}
;function vb(a,b){this.h=b===wb?a:""}
m=vb.prototype;m.X=!0;m.W=function(){return this.h.toString()};
m.ma=!0;m.ja=function(){return 1};
m.toString=function(){return this.h+""};
function xb(a){if(a instanceof vb&&a.constructor===vb)return a.h;Ma(a);return"type_error:TrustedResourceUrl"}
var wb={};var yb=String.prototype.trim?function(a){return a.trim()}:function(a){return/^[\s\xa0]*([\s\S]*?)[\s\xa0]*$/.exec(a)[1]};
function zb(a,b){if(b)a=a.replace(Ab,"&amp;").replace(Bb,"&lt;").replace(Cb,"&gt;").replace(Db,"&quot;").replace(Eb,"&#39;").replace(Fb,"&#0;");else{if(!Gb.test(a))return a;-1!=a.indexOf("&")&&(a=a.replace(Ab,"&amp;"));-1!=a.indexOf("<")&&(a=a.replace(Bb,"&lt;"));-1!=a.indexOf(">")&&(a=a.replace(Cb,"&gt;"));-1!=a.indexOf('"')&&(a=a.replace(Db,"&quot;"));-1!=a.indexOf("'")&&(a=a.replace(Eb,"&#39;"));-1!=a.indexOf("\x00")&&(a=a.replace(Fb,"&#0;"))}return a}
var Ab=/&/g,Bb=/</g,Cb=/>/g,Db=/"/g,Eb=/'/g,Fb=/\x00/g,Gb=/[\x00&<>"']/;function Hb(a,b){this.h=b===Ib?a:""}
m=Hb.prototype;m.X=!0;m.W=function(){return this.h.toString()};
m.ma=!0;m.ja=function(){return 1};
m.toString=function(){return this.h.toString()};
function Jb(a){if(a instanceof Hb&&a.constructor===Hb)return a.h;Ma(a);return"type_error:SafeUrl"}
var Kb=/^(?:audio\/(?:3gpp2|3gpp|aac|L16|midi|mp3|mp4|mpeg|oga|ogg|opus|x-m4a|x-matroska|x-wav|wav|webm)|font\/\w+|image\/(?:bmp|gif|jpeg|jpg|png|tiff|webp|x-icon)|video\/(?:mpeg|mp4|ogg|webm|quicktime|x-matroska))(?:;\w+=(?:\w+|"[\w;,= ]+"))*$/i,Lb=/^data:(.*);base64,[a-z0-9+\/]+=*$/i,Mb=/^(?:(?:https?|mailto|ftp):|[^:/?#]*(?:[/?#]|$))/i;function Nb(a){if(a instanceof Hb)return a;a="object"==typeof a&&a.X?a.W():String(a);Mb.test(a)||(a="about:invalid#zClosurez");return new Hb(a,Ib)}
var Ib={},Ob=new Hb("about:invalid#zClosurez",Ib);var Pb;a:{var Qb=y.navigator;if(Qb){var Rb=Qb.userAgent;if(Rb){Pb=Rb;break a}}Pb=""}function G(a){return-1!=Pb.indexOf(a)}
;function Sb(a,b,c){this.h=c===Tb?a:"";this.i=b}
m=Sb.prototype;m.ma=!0;m.ja=function(){return this.i};
m.X=!0;m.W=function(){return this.h.toString()};
m.toString=function(){return this.h.toString()};
var Tb={};function Ub(a,b){var c=ub();a=c?c.createHTML(a):a;return new Sb(a,b,Tb)}
;function Vb(a,b){b=b instanceof Hb?b:Nb(b);a.href=Jb(b)}
function Wb(a,b){a.rel="stylesheet";a.href=xb(b).toString();(b=a.ownerDocument&&a.ownerDocument.defaultView)&&b!=y?b=Xb(b.document):(null===Yb&&(Yb=Xb(y.document)),b=Yb);b&&a.setAttribute("nonce",b)}
function Zb(a,b){a.src=xb(b);(b=Ga(a.ownerDocument&&a.ownerDocument.defaultView))&&a.setAttribute("nonce",b)}
var Yb=null,$b=/^[\w+/_-]+[=]{0,2}$/;function Xb(a){if(!a.querySelector)return"";var b=a.querySelector("style[nonce]");b||(b=a.querySelector('link[rel="stylesheet"][nonce]'));return b&&(a=b.nonce||b.getAttribute("nonce"))&&$b.test(a)?a:""}
;function ac(a){return a=zb(a,void 0)}
function bc(a){for(var b=0,c=0;c<a.length;++c)b=31*b+a.charCodeAt(c)>>>0;return b}
;var cc=/^(?:([^:/?#.]+):)?(?:\/\/(?:([^\\/?#]*)@)?([^\\/?#]*?)(?::([0-9]+))?(?=[\\/?#]|$))?([^?#]+)?(?:\?([^#]*))?(?:#([\s\S]*))?$/;function dc(a){return a?decodeURI(a):a}
function ec(a){return dc(a.match(cc)[3]||null)}
function fc(a,b,c){if(Array.isArray(b))for(var d=0;d<b.length;d++)fc(a,String(b[d]),c);else null!=b&&c.push(a+(""===b?"":"="+encodeURIComponent(String(b))))}
function gc(a){var b=[],c;for(c in a)fc(c,a[c],b);return b.join("&")}
function hc(a,b){b=gc(b);if(b){var c=a.indexOf("#");0>c&&(c=a.length);var d=a.indexOf("?");if(0>d||d>c){d=c;var e=""}else e=a.substring(d+1,c);a=[a.substr(0,d),e,a.substr(c)];c=a[1];a[1]=b?c?c+"&"+b:b:c;b=a[0]+(a[1]?"?"+a[1]:"")+a[2]}else b=a;return b}
var ic=/#|$/;function H(a,b){var c=void 0;return new (c||(c=Promise))(function(d,e){function f(k){try{h(b.next(k))}catch(l){e(l)}}
function g(k){try{h(b["throw"](k))}catch(l){e(l)}}
function h(k){k.done?d(k.value):(new c(function(l){l(k.value)})).then(f,g)}
h((b=b.apply(a,void 0)).next())})}
;function jc(){return G("iPhone")&&!G("iPod")&&!G("iPad")}
;function kc(a){kc[" "](a);return a}
kc[" "]=Ka;var lc=G("Opera"),mc=G("Trident")||G("MSIE"),nc=G("Edge"),oc=G("Gecko")&&!(-1!=Pb.toLowerCase().indexOf("webkit")&&!G("Edge"))&&!(G("Trident")||G("MSIE"))&&!G("Edge"),pc=-1!=Pb.toLowerCase().indexOf("webkit")&&!G("Edge");function qc(){var a=y.document;return a?a.documentMode:void 0}
var rc;a:{var sc="",tc=function(){var a=Pb;if(oc)return/rv:([^\);]+)(\)|;)/.exec(a);if(nc)return/Edge\/([\d\.]+)/.exec(a);if(mc)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(pc)return/WebKit\/(\S+)/.exec(a);if(lc)return/(?:Version)[ \/]?(\S+)/.exec(a)}();
tc&&(sc=tc?tc[1]:"");if(mc){var uc=qc();if(null!=uc&&uc>parseFloat(sc)){rc=String(uc);break a}}rc=sc}var vc=rc,wc;if(y.document&&mc){var xc=qc();wc=xc?xc:parseInt(vc,10)||void 0}else wc=void 0;var yc=wc;var zc=jc()||G("iPod"),Ac=G("iPad"),Bc=G("Safari")&&!((G("Chrome")||G("CriOS"))&&!G("Edge")||G("Coast")||G("Opera")||G("Edge")||G("Edg/")||G("OPR")||G("Firefox")||G("FxiOS")||G("Silk")||G("Android"))&&!(jc()||G("iPad")||G("iPod"));var Cc={},Dc=null;
function Ec(a){var b=3;Na(a);void 0===b&&(b=0);if(!Dc){Dc={};for(var c="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789".split(""),d=["+/=","+/","-_=","-_.","-_"],e=0;5>e;e++){var f=c.concat(d[e].split(""));Cc[e]=f;for(var g=0;g<f.length;g++){var h=f[g];void 0===Dc[h]&&(Dc[h]=g)}}}b=Cc[b];c=[];for(d=0;d<a.length;d+=3){var k=a[d],l=(e=d+1<a.length)?a[d+1]:0;h=(f=d+2<a.length)?a[d+2]:0;g=k>>2;k=(k&3)<<4|l>>4;l=(l&15)<<2|h>>6;h&=63;f||(h=64,e||(l=64));c.push(b[g],b[k],b[l]||"",b[h]||"")}return c.join("")}
;var K=window;var Fc=!mc||9<=Number(yc);function Gc(a,b){this.x=void 0!==a?a:0;this.y=void 0!==b?b:0}
m=Gc.prototype;m.clone=function(){return new Gc(this.x,this.y)};
m.equals=function(a){return a instanceof Gc&&(this==a?!0:this&&a?this.x==a.x&&this.y==a.y:!1)};
m.ceil=function(){this.x=Math.ceil(this.x);this.y=Math.ceil(this.y);return this};
m.floor=function(){this.x=Math.floor(this.x);this.y=Math.floor(this.y);return this};
m.round=function(){this.x=Math.round(this.x);this.y=Math.round(this.y);return this};function Hc(a,b){this.width=a;this.height=b}
m=Hc.prototype;m.clone=function(){return new Hc(this.width,this.height)};
m.aspectRatio=function(){return this.width/this.height};
m.isEmpty=function(){return!(this.width*this.height)};
m.ceil=function(){this.width=Math.ceil(this.width);this.height=Math.ceil(this.height);return this};
m.floor=function(){this.width=Math.floor(this.width);this.height=Math.floor(this.height);return this};
m.round=function(){this.width=Math.round(this.width);this.height=Math.round(this.height);return this};function Ic(a){var b=document;return"string"===typeof a?b.getElementById(a):a}
function Jc(a,b){hb(b,function(c,d){c&&"object"==typeof c&&c.X&&(c=c.W());"style"==d?a.style.cssText=c:"class"==d?a.className=c:"for"==d?a.htmlFor=c:Kc.hasOwnProperty(d)?a.setAttribute(Kc[d],c):0==d.lastIndexOf("aria-",0)||0==d.lastIndexOf("data-",0)?a.setAttribute(d,c):a[d]=c})}
var Kc={cellpadding:"cellPadding",cellspacing:"cellSpacing",colspan:"colSpan",frameborder:"frameBorder",height:"height",maxlength:"maxLength",nonce:"nonce",role:"role",rowspan:"rowSpan",type:"type",usemap:"useMap",valign:"vAlign",width:"width"};
function Lc(a,b,c){var d=arguments,e=document,f=String(d[0]),g=d[1];if(!Fc&&g&&(g.name||g.type)){f=["<",f];g.name&&f.push(' name="',ac(g.name),'"');if(g.type){f.push(' type="',ac(g.type),'"');var h={};sb(h,g);delete h.type;g=h}f.push(">");f=f.join("")}f=Mc(e,f);g&&("string"===typeof g?f.className=g:Array.isArray(g)?f.className=g.join(" "):Jc(f,g));2<d.length&&Nc(e,f,d);return f}
function Nc(a,b,c){function d(h){h&&b.appendChild("string"===typeof h?a.createTextNode(h):h)}
for(var e=2;e<c.length;e++){var f=c[e];if(!Na(f)||Oa(f)&&0<f.nodeType)d(f);else{a:{if(f&&"number"==typeof f.length){if(Oa(f)){var g="function"==typeof f.item||"string"==typeof f.item;break a}if("function"===typeof f){g="function"==typeof f.item;break a}}g=!1}E(g?fb(f):f,d)}}}
function Mc(a,b){b=String(b);"application/xhtml+xml"===a.contentType&&(b=b.toLowerCase());return a.createElement(b)}
function Oc(a,b){for(var c=0;a;){if(b(a))return a;a=a.parentNode;c++}return null}
;function Pc(a){var b=Qc;if(b)for(var c in b)Object.prototype.hasOwnProperty.call(b,c)&&a.call(void 0,b[c],c,b)}
function Rc(){var a=[];Pc(function(b){a.push(b)});
return a}
var Qc={Ab:"allow-forms",Bb:"allow-modals",Cb:"allow-orientation-lock",Db:"allow-pointer-lock",Eb:"allow-popups",Fb:"allow-popups-to-escape-sandbox",Gb:"allow-presentation",Hb:"allow-same-origin",Ib:"allow-scripts",Jb:"allow-top-navigation",Kb:"allow-top-navigation-by-user-activation"},Sc=Za(function(){return Rc()});
function Tc(){var a=Mc(document,"IFRAME"),b={};E(Sc(),function(c){a.sandbox&&a.sandbox.supports&&a.sandbox.supports(c)&&(b[c]=!0)});
return b}
;function Uc(a){Vc();var b=ub();a=b?b.createScriptURL(a):a;return new vb(a,wb)}
var Vc=Ka;function Wc(a){"number"==typeof a&&(a=Math.round(a)+"px");return a}
;var Xc=(new Date).getTime();function Yc(a){if(!a)return"";a=a.split("#")[0].split("?")[0];a=a.toLowerCase();0==a.indexOf("//")&&(a=window.location.protocol+a);/^[\w\-]*:\/\//.test(a)||(a=window.location.href);var b=a.substring(a.indexOf("://")+3),c=b.indexOf("/");-1!=c&&(b=b.substring(0,c));c=a.substring(0,a.indexOf("://"));if(!c)throw Error("URI is missing protocol: "+a);if("http"!==c&&"https"!==c&&"chrome-extension"!==c&&"moz-extension"!==c&&"file"!==c&&"android-app"!==c&&"chrome-search"!==c&&"chrome-untrusted"!==c&&"chrome"!==
c&&"app"!==c&&"devtools"!==c)throw Error("Invalid URI scheme in origin: "+c);a="";var d=b.indexOf(":");if(-1!=d){var e=b.substring(d+1);b=b.substring(0,d);if("http"===c&&"80"!==e||"https"===c&&"443"!==e)a=":"+e}return c+"://"+b+a}
;function Zc(){function a(){e[0]=1732584193;e[1]=4023233417;e[2]=2562383102;e[3]=271733878;e[4]=3285377520;p=l=0}
function b(n){for(var r=g,q=0;64>q;q+=4)r[q/4]=n[q]<<24|n[q+1]<<16|n[q+2]<<8|n[q+3];for(q=16;80>q;q++)n=r[q-3]^r[q-8]^r[q-14]^r[q-16],r[q]=(n<<1|n>>>31)&4294967295;n=e[0];var D=e[1],I=e[2],J=e[3],ba=e[4];for(q=0;80>q;q++){if(40>q)if(20>q){var U=J^D&(I^J);var O=1518500249}else U=D^I^J,O=1859775393;else 60>q?(U=D&I|J&(D|I),O=2400959708):(U=D^I^J,O=3395469782);U=((n<<5|n>>>27)&4294967295)+U+ba+O+r[q]&4294967295;ba=J;J=I;I=(D<<30|D>>>2)&4294967295;D=n;n=U}e[0]=e[0]+n&4294967295;e[1]=e[1]+D&4294967295;
e[2]=e[2]+I&4294967295;e[3]=e[3]+J&4294967295;e[4]=e[4]+ba&4294967295}
function c(n,r){if("string"===typeof n){n=unescape(encodeURIComponent(n));for(var q=[],D=0,I=n.length;D<I;++D)q.push(n.charCodeAt(D));n=q}r||(r=n.length);q=0;if(0==l)for(;q+64<r;)b(n.slice(q,q+64)),q+=64,p+=64;for(;q<r;)if(f[l++]=n[q++],p++,64==l)for(l=0,b(f);q+64<r;)b(n.slice(q,q+64)),q+=64,p+=64}
function d(){var n=[],r=8*p;56>l?c(h,56-l):c(h,64-(l-56));for(var q=63;56<=q;q--)f[q]=r&255,r>>>=8;b(f);for(q=r=0;5>q;q++)for(var D=24;0<=D;D-=8)n[r++]=e[q]>>D&255;return n}
for(var e=[],f=[],g=[],h=[128],k=1;64>k;++k)h[k]=0;var l,p;a();return{reset:a,update:c,digest:d,Ka:function(){for(var n=d(),r="",q=0;q<n.length;q++)r+="0123456789ABCDEF".charAt(Math.floor(n[q]/16))+"0123456789ABCDEF".charAt(n[q]%16);return r}}}
;function $c(a,b,c){var d=String(y.location.href);return d&&a&&b?[b,ad(Yc(d),a,c||null)].join(" "):null}
function ad(a,b,c){var d=[],e=[];if(1==(Array.isArray(c)?2:1))return e=[b,a],E(d,function(h){e.push(h)}),bd(e.join(" "));
var f=[],g=[];E(c,function(h){g.push(h.key);f.push(h.value)});
c=Math.floor((new Date).getTime()/1E3);e=0==f.length?[c,b,a]:[f.join(":"),c,b,a];E(d,function(h){e.push(h)});
a=bd(e.join(" "));a=[c,a];0==g.length||a.push(g.join(""));return a.join("_")}
function bd(a){var b=Zc();b.update(a);return b.Ka().toLowerCase()}
;var cd={};function dd(a){this.h=a||{cookie:""}}
m=dd.prototype;m.isEnabled=function(){if(!y.navigator.cookieEnabled)return!1;if(!this.isEmpty())return!0;this.set("TESTCOOKIESENABLED","1",{oa:60});if("1"!==this.get("TESTCOOKIESENABLED"))return!1;this.remove("TESTCOOKIESENABLED");return!0};
m.set=function(a,b,c){var d=!1;if("object"===typeof c){var e=c.Pk;d=c.secure||!1;var f=c.domain||void 0;var g=c.path||void 0;var h=c.oa}if(/[;=\s]/.test(a))throw Error('Invalid cookie name "'+a+'"');if(/[;\r\n]/.test(b))throw Error('Invalid cookie value "'+b+'"');void 0===h&&(h=-1);this.h.cookie=a+"="+b+(f?";domain="+f:"")+(g?";path="+g:"")+(0>h?"":0==h?";expires="+(new Date(1970,1,1)).toUTCString():";expires="+(new Date(Date.now()+1E3*h)).toUTCString())+(d?";secure":"")+(null!=e?";samesite="+e:"")};
m.get=function(a,b){for(var c=a+"=",d=(this.h.cookie||"").split(";"),e=0,f;e<d.length;e++){f=yb(d[e]);if(0==f.lastIndexOf(c,0))return f.substr(c.length);if(f==a)return""}return b};
m.remove=function(a,b,c){var d=void 0!==this.get(a);this.set(a,"",{oa:0,path:b,domain:c});return d};
m.isEmpty=function(){return!this.h.cookie};
m.clear=function(){for(var a=(this.h.cookie||"").split(";"),b=[],c=[],d,e,f=0;f<a.length;f++)e=yb(a[f]),d=e.indexOf("="),-1==d?(b.push(""),c.push(e)):(b.push(e.substring(0,d)),c.push(e.substring(d+1)));for(a=b.length-1;0<=a;a--)this.remove(b[a])};
var ed=new dd("undefined"==typeof document?null:document);function fd(a){return!!cd.FPA_SAMESITE_PHASE2_MOD||!(void 0===a||!a)}
function gd(a,b,c,d){(a=y[a])||(a=(new dd(document)).get(b));return a?$c(a,c,d):null}
function hd(a){var b=void 0===b?!1:b;var c=Yc(String(y.location.href)),d=[];var e=b;e=void 0===e?!1:e;var f=y.__SAPISID||y.__APISID||y.__3PSAPISID||y.__OVERRIDE_SID;fd(e)&&(f=f||y.__1PSAPISID);if(f)e=!0;else{var g=new dd(document);f=g.get("SAPISID")||g.get("APISID")||g.get("__Secure-3PAPISID")||g.get("SID");fd(e)&&(f=f||g.get("__Secure-1PAPISID"));e=!!f}e&&(e=(c=0==c.indexOf("https:")||0==c.indexOf("chrome-extension:")||0==c.indexOf("moz-extension:"))?y.__SAPISID:y.__APISID,e||(e=new dd(document),
e=e.get(c?"SAPISID":"APISID")||e.get("__Secure-3PAPISID")),(e=e?$c(e,c?"SAPISIDHASH":"APISIDHASH",a):null)&&d.push(e),c&&fd(b)&&((b=gd("__1PSAPISID","__Secure-1PAPISID","SAPISID1PHASH",a))&&d.push(b),(a=gd("__3PSAPISID","__Secure-3PAPISID","SAPISID3PHASH",a))&&d.push(a)));return 0==d.length?null:d.join(" ")}
;function id(){this.h=[];this.i=-1}
id.prototype.set=function(a,b){b=void 0===b?!0:b;0<=a&&52>a&&0===a%1&&this.h[a]!=b&&(this.h[a]=b,this.i=-1)};
id.prototype.get=function(a){return!!this.h[a]};
function jd(a){-1==a.i&&(a.i=cb(a.h,function(b,c,d){return c?b+Math.pow(2,d):b},0));
return a.i}
;function kd(a,b){this.j=a;this.l=b;this.i=0;this.h=null}
kd.prototype.get=function(){if(0<this.i){this.i--;var a=this.h;this.h=a.next;a.next=null}else a=this.j();return a};
function ld(a,b){a.l(b);100>a.i&&(a.i++,b.next=a.h,a.h=b)}
;var md;
function nd(){var a=y.MessageChannel;"undefined"===typeof a&&"undefined"!==typeof window&&window.postMessage&&window.addEventListener&&!G("Presto")&&(a=function(){var e=Mc(document,"IFRAME");e.style.display="none";document.documentElement.appendChild(e);var f=e.contentWindow;e=f.document;e.open();e.close();var g="callImmediate"+Math.random(),h="file:"==f.location.protocol?"*":f.location.protocol+"//"+f.location.host;e=B(function(k){if(("*"==h||k.origin==h)&&k.data==g)this.port1.onmessage()},this);
f.addEventListener("message",e,!1);this.port1={};this.port2={postMessage:function(){f.postMessage(g,h)}}});
if("undefined"!==typeof a&&!G("Trident")&&!G("MSIE")){var b=new a,c={},d=c;b.port1.onmessage=function(){if(void 0!==c.next){c=c.next;var e=c.ta;c.ta=null;e()}};
return function(e){d.next={ta:e};d=d.next;b.port2.postMessage(0)}}return function(e){y.setTimeout(e,0)}}
;function od(a){y.setTimeout(function(){throw a;},0)}
;function pd(){this.i=this.h=null}
pd.prototype.add=function(a,b){var c=qd.get();c.set(a,b);this.i?this.i.next=c:this.h=c;this.i=c};
pd.prototype.remove=function(){var a=null;this.h&&(a=this.h,this.h=this.h.next,this.h||(this.i=null),a.next=null);return a};
var qd=new kd(function(){return new rd},function(a){return a.reset()});
function rd(){this.next=this.scope=this.h=null}
rd.prototype.set=function(a,b){this.h=a;this.scope=b;this.next=null};
rd.prototype.reset=function(){this.next=this.scope=this.h=null};function sd(a,b){td||ud();vd||(td(),vd=!0);wd.add(a,b)}
var td;function ud(){if(y.Promise&&y.Promise.resolve){var a=y.Promise.resolve(void 0);td=function(){a.then(xd)}}else td=function(){var b=xd;
"function"!==typeof y.setImmediate||y.Window&&y.Window.prototype&&!G("Edge")&&y.Window.prototype.setImmediate==y.setImmediate?(md||(md=nd()),md(b)):y.setImmediate(b)}}
var vd=!1,wd=new pd;function xd(){for(var a;a=wd.remove();){try{a.h.call(a.scope)}catch(b){od(b)}ld(qd,a)}vd=!1}
;function yd(){this.i=-1}
;function zd(){this.i=64;this.h=[];this.m=[];this.o=[];this.l=[];this.l[0]=128;for(var a=1;a<this.i;++a)this.l[a]=0;this.u=this.j=0;this.reset()}
C(zd,yd);zd.prototype.reset=function(){this.h[0]=1732584193;this.h[1]=4023233417;this.h[2]=2562383102;this.h[3]=271733878;this.h[4]=3285377520;this.u=this.j=0};
function Ad(a,b,c){c||(c=0);var d=a.o;if("string"===typeof b)for(var e=0;16>e;e++)d[e]=b.charCodeAt(c)<<24|b.charCodeAt(c+1)<<16|b.charCodeAt(c+2)<<8|b.charCodeAt(c+3),c+=4;else for(e=0;16>e;e++)d[e]=b[c]<<24|b[c+1]<<16|b[c+2]<<8|b[c+3],c+=4;for(e=16;80>e;e++){var f=d[e-3]^d[e-8]^d[e-14]^d[e-16];d[e]=(f<<1|f>>>31)&4294967295}b=a.h[0];c=a.h[1];var g=a.h[2],h=a.h[3],k=a.h[4];for(e=0;80>e;e++){if(40>e)if(20>e){f=h^c&(g^h);var l=1518500249}else f=c^g^h,l=1859775393;else 60>e?(f=c&g|h&(c|g),l=2400959708):
(f=c^g^h,l=3395469782);f=(b<<5|b>>>27)+f+k+l+d[e]&4294967295;k=h;h=g;g=(c<<30|c>>>2)&4294967295;c=b;b=f}a.h[0]=a.h[0]+b&4294967295;a.h[1]=a.h[1]+c&4294967295;a.h[2]=a.h[2]+g&4294967295;a.h[3]=a.h[3]+h&4294967295;a.h[4]=a.h[4]+k&4294967295}
zd.prototype.update=function(a,b){if(null!=a){void 0===b&&(b=a.length);for(var c=b-this.i,d=0,e=this.m,f=this.j;d<b;){if(0==f)for(;d<=c;)Ad(this,a,d),d+=this.i;if("string"===typeof a)for(;d<b;){if(e[f]=a.charCodeAt(d),++f,++d,f==this.i){Ad(this,e);f=0;break}}else for(;d<b;)if(e[f]=a[d],++f,++d,f==this.i){Ad(this,e);f=0;break}}this.j=f;this.u+=b}};
zd.prototype.digest=function(){var a=[],b=8*this.u;56>this.j?this.update(this.l,56-this.j):this.update(this.l,this.i-(this.j-56));for(var c=this.i-1;56<=c;c--)this.m[c]=b&255,b/=256;Ad(this,this.m);for(c=b=0;5>c;c++)for(var d=24;0<=d;d-=8)a[b]=this.h[c]>>d&255,++b;return a};function Bd(a){var b=A("window.location.href");null==a&&(a='Unknown Error of type "null/undefined"');if("string"===typeof a)return{message:a,name:"Unknown error",lineNumber:"Not available",fileName:b,stack:"Not available"};var c=!1;try{var d=a.lineNumber||a.line||"Not available"}catch(g){d="Not available",c=!0}try{var e=a.fileName||a.filename||a.sourceURL||y.$googDebugFname||b}catch(g){e="Not available",c=!0}b=Cd(a);if(!(!c&&a.lineNumber&&a.fileName&&a.stack&&a.message&&a.name)){c=a.message;if(null==
c){if(a.constructor&&a.constructor instanceof Function){if(a.constructor.name)c=a.constructor.name;else if(c=a.constructor,Dd[c])c=Dd[c];else{c=String(c);if(!Dd[c]){var f=/function\s+([^\(]+)/m.exec(c);Dd[c]=f?f[1]:"[Anonymous]"}c=Dd[c]}c='Unknown Error of type "'+c+'"'}else c="Unknown Error of unknown type";"function"===typeof a.toString&&Object.prototype.toString!==a.toString&&(c+=": "+a.toString())}return{message:c,name:a.name||"UnknownError",lineNumber:d,fileName:e,stack:b||"Not available"}}a.stack=
b;return{message:a.message,name:a.name,lineNumber:a.lineNumber,fileName:a.fileName,stack:a.stack}}
function Cd(a,b){b||(b={});b[Ed(a)]=!0;var c=a.stack||"";(a=a.Ja)&&!b[Ed(a)]&&(c+="\nCaused by: ",a.stack&&0==a.stack.indexOf(a.toString())||(c+="string"===typeof a?a:a.message+"\n"),c+=Cd(a,b));return c}
function Ed(a){var b="";"function"===typeof a.toString&&(b=""+a);return b+a.stack}
var Dd={};function Fd(a){a&&"function"==typeof a.dispose&&a.dispose()}
;function Gd(a){for(var b=0,c=arguments.length;b<c;++b){var d=arguments[b];Na(d)?Gd.apply(null,d):Fd(d)}}
;function L(){this.h=this.h;this.u=this.u}
L.prototype.h=!1;L.prototype.dispose=function(){this.h||(this.h=!0,this.D())};
function Hd(a,b){a.h?b():(a.u||(a.u=[]),a.u.push(b))}
L.prototype.D=function(){if(this.u)for(;this.u.length;)this.u.shift()()};function Id(a){return"string"==typeof a.className?a.className:a.getAttribute&&a.getAttribute("class")||""}
function Jd(a,b){"string"==typeof a.className?a.className=b:a.setAttribute&&a.setAttribute("class",b)}
function Kd(a,b){a.classList?b=a.classList.contains(b):(a=a.classList?a.classList:Id(a).match(/\S+/g)||[],b=0<=$a(a,b));return b}
function Ld(){var a=document.body;a.classList?a.classList.remove("inverted-hdpi"):Kd(a,"inverted-hdpi")&&Jd(a,ab(a.classList?a.classList:Id(a).match(/\S+/g)||[],function(b){return"inverted-hdpi"!=b}).join(" "))}
;var Md="StopIteration"in y?y.StopIteration:{message:"StopIteration",stack:""};function Nd(){}
Nd.prototype.next=function(){throw Md;};
Nd.prototype.O=function(){return this};
function Od(a){if(a instanceof Nd)return a;if("function"==typeof a.O)return a.O(!1);if(Na(a)){var b=0,c=new Nd;c.next=function(){for(;;){if(b>=a.length)throw Md;if(b in a)return a[b++];b++}};
return c}throw Error("Not implemented");}
function Pd(a,b){if(Na(a))try{E(a,b,void 0)}catch(c){if(c!==Md)throw c;}else{a=Od(a);try{for(;;)b.call(void 0,a.next(),void 0,a)}catch(c){if(c!==Md)throw c;}}}
function Qd(a){if(Na(a))return fb(a);a=Od(a);var b=[];Pd(a,function(c){b.push(c)});
return b}
;function Rd(a,b){this.i={};this.h=[];this.R=this.j=0;var c=arguments.length;if(1<c){if(c%2)throw Error("Uneven number of arguments");for(var d=0;d<c;d+=2)this.set(arguments[d],arguments[d+1])}else if(a)if(a instanceof Rd)for(c=Sd(a),d=0;d<c.length;d++)this.set(c[d],a.get(c[d]));else for(d in a)this.set(d,a[d])}
function Sd(a){Td(a);return a.h.concat()}
m=Rd.prototype;m.equals=function(a,b){if(this===a)return!0;if(this.j!=a.j)return!1;b=b||Ud;Td(this);for(var c,d=0;c=this.h[d];d++)if(!b(this.get(c),a.get(c)))return!1;return!0};
function Ud(a,b){return a===b}
m.isEmpty=function(){return 0==this.j};
m.clear=function(){this.i={};this.R=this.j=this.h.length=0};
m.remove=function(a){return Object.prototype.hasOwnProperty.call(this.i,a)?(delete this.i[a],this.j--,this.R++,this.h.length>2*this.j&&Td(this),!0):!1};
function Td(a){if(a.j!=a.h.length){for(var b=0,c=0;b<a.h.length;){var d=a.h[b];Object.prototype.hasOwnProperty.call(a.i,d)&&(a.h[c++]=d);b++}a.h.length=c}if(a.j!=a.h.length){var e={};for(c=b=0;b<a.h.length;)d=a.h[b],Object.prototype.hasOwnProperty.call(e,d)||(a.h[c++]=d,e[d]=1),b++;a.h.length=c}}
m.get=function(a,b){return Object.prototype.hasOwnProperty.call(this.i,a)?this.i[a]:b};
m.set=function(a,b){Object.prototype.hasOwnProperty.call(this.i,a)||(this.j++,this.h.push(a),this.R++);this.i[a]=b};
m.forEach=function(a,b){for(var c=Sd(this),d=0;d<c.length;d++){var e=c[d],f=this.get(e);a.call(b,f,e,this)}};
m.clone=function(){return new Rd(this)};
m.O=function(a){Td(this);var b=0,c=this.R,d=this,e=new Nd;e.next=function(){if(c!=d.R)throw Error("The map has changed since the iterator was created");if(b>=d.h.length)throw Md;var f=d.h[b++];return a?f:d.i[f]};
return e};var Vd=function(){if(!y.addEventListener||!Object.defineProperty)return!1;var a=!1,b=Object.defineProperty({},"passive",{get:function(){a=!0}});
try{y.addEventListener("test",Ka,b),y.removeEventListener("test",Ka,b)}catch(c){}return a}();function Wd(a,b){this.type=a;this.h=this.target=b;this.defaultPrevented=this.j=!1}
Wd.prototype.stopPropagation=function(){this.j=!0};
Wd.prototype.preventDefault=function(){this.defaultPrevented=!0};function Xd(a,b){Wd.call(this,a?a.type:"");this.relatedTarget=this.h=this.target=null;this.button=this.screenY=this.screenX=this.clientY=this.clientX=0;this.key="";this.charCode=this.keyCode=0;this.metaKey=this.shiftKey=this.altKey=this.ctrlKey=!1;this.state=null;this.pointerId=0;this.pointerType="";this.i=null;a&&this.init(a,b)}
C(Xd,Wd);var Yd={2:"touch",3:"pen",4:"mouse"};
Xd.prototype.init=function(a,b){var c=this.type=a.type,d=a.changedTouches&&a.changedTouches.length?a.changedTouches[0]:null;this.target=a.target||a.srcElement;this.h=b;if(b=a.relatedTarget){if(oc){a:{try{kc(b.nodeName);var e=!0;break a}catch(f){}e=!1}e||(b=null)}}else"mouseover"==c?b=a.fromElement:"mouseout"==c&&(b=a.toElement);this.relatedTarget=b;d?(this.clientX=void 0!==d.clientX?d.clientX:d.pageX,this.clientY=void 0!==d.clientY?d.clientY:d.pageY,this.screenX=d.screenX||0,this.screenY=d.screenY||
0):(this.clientX=void 0!==a.clientX?a.clientX:a.pageX,this.clientY=void 0!==a.clientY?a.clientY:a.pageY,this.screenX=a.screenX||0,this.screenY=a.screenY||0);this.button=a.button;this.keyCode=a.keyCode||0;this.key=a.key||"";this.charCode=a.charCode||("keypress"==c?a.keyCode:0);this.ctrlKey=a.ctrlKey;this.altKey=a.altKey;this.shiftKey=a.shiftKey;this.metaKey=a.metaKey;this.pointerId=a.pointerId||0;this.pointerType="string"===typeof a.pointerType?a.pointerType:Yd[a.pointerType]||"";this.state=a.state;
this.i=a;a.defaultPrevented&&Xd.M.preventDefault.call(this)};
Xd.prototype.stopPropagation=function(){Xd.M.stopPropagation.call(this);this.i.stopPropagation?this.i.stopPropagation():this.i.cancelBubble=!0};
Xd.prototype.preventDefault=function(){Xd.M.preventDefault.call(this);var a=this.i;a.preventDefault?a.preventDefault():a.returnValue=!1};var Zd="closure_listenable_"+(1E6*Math.random()|0);var $d=0;function ae(a,b,c,d,e){this.listener=a;this.h=null;this.src=b;this.type=c;this.capture=!!d;this.fa=e;this.key=++$d;this.Z=this.ca=!1}
function be(a){a.Z=!0;a.listener=null;a.h=null;a.src=null;a.fa=null}
;function ce(a){this.src=a;this.listeners={};this.h=0}
ce.prototype.add=function(a,b,c,d,e){var f=a.toString();a=this.listeners[f];a||(a=this.listeners[f]=[],this.h++);var g=de(a,b,d,e);-1<g?(b=a[g],c||(b.ca=!1)):(b=new ae(b,this.src,f,!!d,e),b.ca=c,a.push(b));return b};
ce.prototype.remove=function(a,b,c,d){a=a.toString();if(!(a in this.listeners))return!1;var e=this.listeners[a];b=de(e,b,c,d);return-1<b?(be(e[b]),Array.prototype.splice.call(e,b,1),0==e.length&&(delete this.listeners[a],this.h--),!0):!1};
function ee(a,b){var c=b.type;c in a.listeners&&eb(a.listeners[c],b)&&(be(b),0==a.listeners[c].length&&(delete a.listeners[c],a.h--))}
function de(a,b,c,d){for(var e=0;e<a.length;++e){var f=a[e];if(!f.Z&&f.listener==b&&f.capture==!!c&&f.fa==d)return e}return-1}
;var fe="closure_lm_"+(1E6*Math.random()|0),ge={},he=0;function ie(a,b,c,d,e){if(d&&d.once)je(a,b,c,d,e);else if(Array.isArray(b))for(var f=0;f<b.length;f++)ie(a,b[f],c,d,e);else c=ke(c),a&&a[Zd]?le(a,b,c,Oa(d)?!!d.capture:!!d,e):me(a,b,c,!1,d,e)}
function me(a,b,c,d,e,f){if(!b)throw Error("Invalid event type");var g=Oa(e)?!!e.capture:!!e,h=ne(a);h||(a[fe]=h=new ce(a));c=h.add(b,c,d,g,f);if(!c.h){d=oe();c.h=d;d.src=a;d.listener=c;if(a.addEventListener)Vd||(e=g),void 0===e&&(e=!1),a.addEventListener(b.toString(),d,e);else if(a.attachEvent)a.attachEvent(pe(b.toString()),d);else if(a.addListener&&a.removeListener)a.addListener(d);else throw Error("addEventListener and attachEvent are unavailable.");he++}}
function oe(){function a(c){return b.call(a.src,a.listener,c)}
var b=qe;return a}
function je(a,b,c,d,e){if(Array.isArray(b))for(var f=0;f<b.length;f++)je(a,b[f],c,d,e);else c=ke(c),a&&a[Zd]?a.j.add(String(b),c,!0,Oa(d)?!!d.capture:!!d,e):me(a,b,c,!0,d,e)}
function re(a,b,c,d,e){if(Array.isArray(b))for(var f=0;f<b.length;f++)re(a,b[f],c,d,e);else(d=Oa(d)?!!d.capture:!!d,c=ke(c),a&&a[Zd])?a.j.remove(String(b),c,d,e):a&&(a=ne(a))&&(b=a.listeners[b.toString()],a=-1,b&&(a=de(b,c,d,e)),(c=-1<a?b[a]:null)&&se(c))}
function se(a){if("number"!==typeof a&&a&&!a.Z){var b=a.src;if(b&&b[Zd])ee(b.j,a);else{var c=a.type,d=a.h;b.removeEventListener?b.removeEventListener(c,d,a.capture):b.detachEvent?b.detachEvent(pe(c),d):b.addListener&&b.removeListener&&b.removeListener(d);he--;(c=ne(b))?(ee(c,a),0==c.h&&(c.src=null,b[fe]=null)):be(a)}}}
function pe(a){return a in ge?ge[a]:ge[a]="on"+a}
function qe(a,b){if(a.Z)a=!0;else{b=new Xd(b,this);var c=a.listener,d=a.fa||a.src;a.ca&&se(a);a=c.call(d,b)}return a}
function ne(a){a=a[fe];return a instanceof ce?a:null}
var te="__closure_events_fn_"+(1E9*Math.random()>>>0);function ke(a){if("function"===typeof a)return a;a[te]||(a[te]=function(b){return a.handleEvent(b)});
return a[te]}
;function ue(){L.call(this);this.j=new ce(this);this.N=this;this.F=null}
C(ue,L);ue.prototype[Zd]=!0;ue.prototype.addEventListener=function(a,b,c,d){ie(this,a,b,c,d)};
ue.prototype.removeEventListener=function(a,b,c,d){re(this,a,b,c,d)};
function ve(a,b){var c=a.F;if(c){var d=[];for(var e=1;c;c=c.F)d.push(c),++e}a=a.N;c=b.type||b;"string"===typeof b?b=new Wd(b,a):b instanceof Wd?b.target=b.target||a:(e=b,b=new Wd(c,a),sb(b,e));e=!0;if(d)for(var f=d.length-1;!b.j&&0<=f;f--){var g=b.h=d[f];e=we(g,c,!0,b)&&e}b.j||(g=b.h=a,e=we(g,c,!0,b)&&e,b.j||(e=we(g,c,!1,b)&&e));if(d)for(f=0;!b.j&&f<d.length;f++)g=b.h=d[f],e=we(g,c,!1,b)&&e}
ue.prototype.D=function(){ue.M.D.call(this);if(this.j){var a=this.j,b=0,c;for(c in a.listeners){for(var d=a.listeners[c],e=0;e<d.length;e++)++b,be(d[e]);delete a.listeners[c];a.h--}}this.F=null};
function le(a,b,c,d,e){a.j.add(String(b),c,!1,d,e)}
function we(a,b,c,d){b=a.j.listeners[String(b)];if(!b)return!0;b=b.concat();for(var e=!0,f=0;f<b.length;++f){var g=b[f];if(g&&!g.Z&&g.capture==c){var h=g.listener,k=g.fa||g.src;g.ca&&ee(a.j,g);e=!1!==h.call(k,d)&&e}}return e&&!d.defaultPrevented}
;function xe(a){var b=[];ye(new ze,a,b);return b.join("")}
function ze(){}
function ye(a,b,c){if(null==b)c.push("null");else{if("object"==typeof b){if(Array.isArray(b)){var d=b;b=d.length;c.push("[");for(var e="",f=0;f<b;f++)c.push(e),ye(a,d[f],c),e=",";c.push("]");return}if(b instanceof String||b instanceof Number||b instanceof Boolean)b=b.valueOf();else{c.push("{");e="";for(d in b)Object.prototype.hasOwnProperty.call(b,d)&&(f=b[d],"function"!=typeof f&&(c.push(e),Ae(d,c),c.push(":"),ye(a,f,c),e=","));c.push("}");return}}switch(typeof b){case "string":Ae(b,c);break;case "number":c.push(isFinite(b)&&
!isNaN(b)?String(b):"null");break;case "boolean":c.push(String(b));break;case "function":c.push("null");break;default:throw Error("Unknown type: "+typeof b);}}}
var Be={'"':'\\"',"\\":"\\\\","/":"\\/","\b":"\\b","\f":"\\f","\n":"\\n","\r":"\\r","\t":"\\t","\x0B":"\\u000b"},Ce=/\uffff/.test("\uffff")?/[\\"\x00-\x1f\x7f-\uffff]/g:/[\\"\x00-\x1f\x7f-\xff]/g;function Ae(a,b){b.push('"',a.replace(Ce,function(c){var d=Be[c];d||(d="\\u"+(c.charCodeAt(0)|65536).toString(16).substr(1),Be[c]=d);return d}),'"')}
;function De(a){if(!a)return!1;try{return!!a.$goog_Thenable}catch(b){return!1}}
;function Ee(a){this.h=0;this.o=void 0;this.l=this.i=this.j=null;this.u=this.m=!1;if(a!=Ka)try{var b=this;a.call(void 0,function(c){Fe(b,2,c)},function(c){Fe(b,3,c)})}catch(c){Fe(this,3,c)}}
function Ge(){this.next=this.context=this.onRejected=this.i=this.h=null;this.j=!1}
Ge.prototype.reset=function(){this.context=this.onRejected=this.i=this.h=null;this.j=!1};
var He=new kd(function(){return new Ge},function(a){a.reset()});
function Ie(a,b,c){var d=He.get();d.i=a;d.onRejected=b;d.context=c;return d}
function Je(a){return new Ee(function(b,c){c(a)})}
Ee.prototype.then=function(a,b,c){return Ke(this,"function"===typeof a?a:null,"function"===typeof b?b:null,c)};
Ee.prototype.$goog_Thenable=!0;function Le(a,b){return Ke(a,null,b,void 0)}
Ee.prototype.cancel=function(a){if(0==this.h){var b=new Me(a);sd(function(){Ne(this,b)},this)}};
function Ne(a,b){if(0==a.h)if(a.j){var c=a.j;if(c.i){for(var d=0,e=null,f=null,g=c.i;g&&(g.j||(d++,g.h==a&&(e=g),!(e&&1<d)));g=g.next)e||(f=g);e&&(0==c.h&&1==d?Ne(c,b):(f?(d=f,d.next==c.l&&(c.l=d),d.next=d.next.next):Oe(c),Pe(c,e,3,b)))}a.j=null}else Fe(a,3,b)}
function Qe(a,b){a.i||2!=a.h&&3!=a.h||Re(a);a.l?a.l.next=b:a.i=b;a.l=b}
function Ke(a,b,c,d){var e=Ie(null,null,null);e.h=new Ee(function(f,g){e.i=b?function(h){try{var k=b.call(d,h);f(k)}catch(l){g(l)}}:f;
e.onRejected=c?function(h){try{var k=c.call(d,h);void 0===k&&h instanceof Me?g(h):f(k)}catch(l){g(l)}}:g});
e.h.j=a;Qe(a,e);return e.h}
Ee.prototype.C=function(a){this.h=0;Fe(this,2,a)};
Ee.prototype.F=function(a){this.h=0;Fe(this,3,a)};
function Fe(a,b,c){if(0==a.h){a===c&&(b=3,c=new TypeError("Promise cannot resolve to itself"));a.h=1;a:{var d=c,e=a.C,f=a.F;if(d instanceof Ee){Qe(d,Ie(e||Ka,f||null,a));var g=!0}else if(De(d))d.then(e,f,a),g=!0;else{if(Oa(d))try{var h=d.then;if("function"===typeof h){Se(d,h,e,f,a);g=!0;break a}}catch(k){f.call(a,k);g=!0;break a}g=!1}}g||(a.o=c,a.h=b,a.j=null,Re(a),3!=b||c instanceof Me||Te(a,c))}}
function Se(a,b,c,d,e){function f(k){h||(h=!0,d.call(e,k))}
function g(k){h||(h=!0,c.call(e,k))}
var h=!1;try{b.call(a,g,f)}catch(k){f(k)}}
function Re(a){a.m||(a.m=!0,sd(a.B,a))}
function Oe(a){var b=null;a.i&&(b=a.i,a.i=b.next,b.next=null);a.i||(a.l=null);return b}
Ee.prototype.B=function(){for(var a;a=Oe(this);)Pe(this,a,this.h,this.o);this.m=!1};
function Pe(a,b,c,d){if(3==c&&b.onRejected&&!b.j)for(;a&&a.u;a=a.j)a.u=!1;if(b.h)b.h.j=null,Ue(b,c,d);else try{b.j?b.i.call(b.context):Ue(b,c,d)}catch(e){Ve.call(null,e)}ld(He,b)}
function Ue(a,b,c){2==b?a.i.call(a.context,c):a.onRejected&&a.onRejected.call(a.context,c)}
function Te(a,b){a.u=!0;sd(function(){a.u&&Ve.call(null,b)})}
var Ve=od;function Me(a){Xa.call(this,a)}
C(Me,Xa);Me.prototype.name="cancel";function M(a){L.call(this);this.o=1;this.l=[];this.m=0;this.i=[];this.j={};this.B=!!a}
C(M,L);m=M.prototype;m.subscribe=function(a,b,c){var d=this.j[a];d||(d=this.j[a]=[]);var e=this.o;this.i[e]=a;this.i[e+1]=b;this.i[e+2]=c;this.o=e+3;d.push(e);return e};
function We(a,b,c,d){if(b=a.j[b]){var e=a.i;(b=db(b,function(f){return e[f+1]==c&&e[f+2]==d}))&&a.Y(b)}}
m.Y=function(a){var b=this.i[a];if(b){var c=this.j[b];0!=this.m?(this.l.push(a),this.i[a+1]=Ka):(c&&eb(c,a),delete this.i[a],delete this.i[a+1],delete this.i[a+2])}return!!b};
m.S=function(a,b){var c=this.j[a];if(c){for(var d=Array(arguments.length-1),e=1,f=arguments.length;e<f;e++)d[e-1]=arguments[e];if(this.B)for(e=0;e<c.length;e++){var g=c[e];Xe(this.i[g+1],this.i[g+2],d)}else{this.m++;try{for(e=0,f=c.length;e<f;e++)g=c[e],this.i[g+1].apply(this.i[g+2],d)}finally{if(this.m--,0<this.l.length&&0==this.m)for(;c=this.l.pop();)this.Y(c)}}return 0!=e}return!1};
function Xe(a,b,c){sd(function(){a.apply(b,c)})}
m.clear=function(a){if(a){var b=this.j[a];b&&(E(b,this.Y,this),delete this.j[a])}else this.i.length=0,this.j={}};
m.D=function(){M.M.D.call(this);this.clear();this.l.length=0};function Ye(a){this.h=a}
Ye.prototype.set=function(a,b){void 0===b?this.h.remove(a):this.h.set(a,xe(b))};
Ye.prototype.get=function(a){try{var b=this.h.get(a)}catch(c){return}if(null!==b)try{return JSON.parse(b)}catch(c){throw"Storage: Invalid value was encountered";}};
Ye.prototype.remove=function(a){this.h.remove(a)};function Ze(a){this.h=a}
C(Ze,Ye);function $e(a){this.data=a}
function af(a){return void 0===a||a instanceof $e?a:new $e(a)}
Ze.prototype.set=function(a,b){Ze.M.set.call(this,a,af(b))};
Ze.prototype.i=function(a){a=Ze.M.get.call(this,a);if(void 0===a||a instanceof Object)return a;throw"Storage: Invalid value was encountered";};
Ze.prototype.get=function(a){if(a=this.i(a)){if(a=a.data,void 0===a)throw"Storage: Invalid value was encountered";}else a=void 0;return a};function bf(a){this.h=a}
C(bf,Ze);bf.prototype.set=function(a,b,c){if(b=af(b)){if(c){if(c<Date.now()){bf.prototype.remove.call(this,a);return}b.expiration=c}b.creation=Date.now()}bf.M.set.call(this,a,b)};
bf.prototype.i=function(a){var b=bf.M.i.call(this,a);if(b){var c=b.creation,d=b.expiration;if(d&&d<Date.now()||c&&c>Date.now())bf.prototype.remove.call(this,a);else return b}};function cf(){}
;function df(){}
C(df,cf);df.prototype.clear=function(){var a=Qd(this.O(!0)),b=this;E(a,function(c){b.remove(c)})};function ef(a){this.h=a}
C(ef,df);m=ef.prototype;m.isAvailable=function(){if(!this.h)return!1;try{return this.h.setItem("__sak","1"),this.h.removeItem("__sak"),!0}catch(a){return!1}};
m.set=function(a,b){try{this.h.setItem(a,b)}catch(c){if(0==this.h.length)throw"Storage mechanism: Storage disabled";throw"Storage mechanism: Quota exceeded";}};
m.get=function(a){a=this.h.getItem(a);if("string"!==typeof a&&null!==a)throw"Storage mechanism: Invalid value was encountered";return a};
m.remove=function(a){this.h.removeItem(a)};
m.O=function(a){var b=0,c=this.h,d=new Nd;d.next=function(){if(b>=c.length)throw Md;var e=c.key(b++);if(a)return e;e=c.getItem(e);if("string"!==typeof e)throw"Storage mechanism: Invalid value was encountered";return e};
return d};
m.clear=function(){this.h.clear()};
m.key=function(a){return this.h.key(a)};function ff(){var a=null;try{a=window.localStorage||null}catch(b){}this.h=a}
C(ff,ef);function gf(a,b){this.i=a;this.h=null;if(mc&&!(9<=Number(yc))){hf||(hf=new Rd);this.h=hf.get(a);this.h||(b?this.h=document.getElementById(b):(this.h=document.createElement("userdata"),this.h.addBehavior("#default#userData"),document.body.appendChild(this.h)),hf.set(a,this.h));try{this.h.load(this.i)}catch(c){this.h=null}}}
C(gf,df);var jf={".":".2E","!":".21","~":".7E","*":".2A","'":".27","(":".28",")":".29","%":"."},hf=null;function kf(a){return"_"+encodeURIComponent(a).replace(/[.!~*'()%]/g,function(b){return jf[b]})}
m=gf.prototype;m.isAvailable=function(){return!!this.h};
m.set=function(a,b){this.h.setAttribute(kf(a),b);lf(this)};
m.get=function(a){a=this.h.getAttribute(kf(a));if("string"!==typeof a&&null!==a)throw"Storage mechanism: Invalid value was encountered";return a};
m.remove=function(a){this.h.removeAttribute(kf(a));lf(this)};
m.O=function(a){var b=0,c=this.h.XMLDocument.documentElement.attributes,d=new Nd;d.next=function(){if(b>=c.length)throw Md;var e=c[b++];if(a)return decodeURIComponent(e.nodeName.replace(/\./g,"%")).substr(1);e=e.nodeValue;if("string"!==typeof e)throw"Storage mechanism: Invalid value was encountered";return e};
return d};
m.clear=function(){for(var a=this.h.XMLDocument.documentElement,b=a.attributes.length;0<b;b--)a.removeAttribute(a.attributes[b-1].nodeName);lf(this)};
function lf(a){try{a.h.save(a.i)}catch(b){throw"Storage mechanism: Quota exceeded";}}
;function mf(a,b){this.i=a;this.h=b+"::"}
C(mf,df);mf.prototype.set=function(a,b){this.i.set(this.h+a,b)};
mf.prototype.get=function(a){return this.i.get(this.h+a)};
mf.prototype.remove=function(a){this.i.remove(this.h+a)};
mf.prototype.O=function(a){var b=this.i.O(!0),c=this,d=new Nd;d.next=function(){for(var e=b.next();e.substr(0,c.h.length)!=c.h;)e=b.next();return a?e.substr(c.h.length):c.i.get(e)};
return d};function nf(a,b){1<b.length?a[b[0]]=b[1]:1===b.length&&Object.assign(a,b[0])}
;var of=window.yt&&window.yt.config_||window.ytcfg&&window.ytcfg.data_||{};z("yt.config_",of,void 0);function N(a){nf(of,arguments)}
function F(a,b){return a in of?of[a]:b}
;var pf=[];function qf(a){pf.forEach(function(b){return b(a)})}
function rf(a){return a&&window.yterr?function(){try{return a.apply(this,arguments)}catch(b){sf(b)}}:a}
function sf(a){var b=A("yt.logging.errors.log");b?b(a,"ERROR",void 0,void 0,void 0):(b=F("ERRORS",[]),b.push([a,"ERROR",void 0,void 0,void 0]),N("ERRORS",b));qf(a)}
function tf(a){var b=A("yt.logging.errors.log");b?b(a,"WARNING",void 0,void 0,void 0):(b=F("ERRORS",[]),b.push([a,"WARNING",void 0,void 0,void 0]),N("ERRORS",b))}
;var uf=window.yt&&window.yt.msgs_||window.ytcfg&&window.ytcfg.msgs||{};z("yt.msgs_",uf,void 0);function vf(a){nf(uf,arguments)}
;function Q(a){a=wf(a);return"string"===typeof a&&"false"===a?!1:!!a}
function xf(a,b){a=wf(a);return void 0===a&&void 0!==b?b:Number(a||0)}
function wf(a){var b=F("EXPERIMENTS_FORCED_FLAGS",{});return void 0!==b[a]?b[a]:F("EXPERIMENT_FLAGS",{})[a]}
;var yf=0,zf=pc?"webkit":oc?"moz":mc?"ms":lc?"o":"";z("ytDomDomGetNextId",A("ytDomDomGetNextId")||function(){return++yf},void 0);var Af={stopImmediatePropagation:1,stopPropagation:1,preventMouseEvent:1,preventManipulation:1,preventDefault:1,layerX:1,layerY:1,screenX:1,screenY:1,scale:1,rotation:1,webkitMovementX:1,webkitMovementY:1};
function Bf(a){this.type="";this.state=this.source=this.data=this.currentTarget=this.relatedTarget=this.target=null;this.charCode=this.keyCode=0;this.metaKey=this.shiftKey=this.ctrlKey=this.altKey=!1;this.clientY=this.clientX=0;this.changedTouches=this.touches=null;try{if(a=a||window.event){this.event=a;for(var b in a)b in Af||(this[b]=a[b]);var c=a.target||a.srcElement;c&&3==c.nodeType&&(c=c.parentNode);this.target=c;var d=a.relatedTarget;if(d)try{d=d.nodeName?d:null}catch(e){d=null}else"mouseover"==
this.type?d=a.fromElement:"mouseout"==this.type&&(d=a.toElement);this.relatedTarget=d;this.clientX=void 0!=a.clientX?a.clientX:a.pageX;this.clientY=void 0!=a.clientY?a.clientY:a.pageY;this.keyCode=a.keyCode?a.keyCode:a.which;this.charCode=a.charCode||("keypress"==this.type?this.keyCode:0);this.altKey=a.altKey;this.ctrlKey=a.ctrlKey;this.shiftKey=a.shiftKey;this.metaKey=a.metaKey;this.h=a.pageX;this.i=a.pageY}}catch(e){}}
function Cf(a){if(document.body&&document.documentElement){var b=document.body.scrollTop+document.documentElement.scrollTop;a.h=a.clientX+(document.body.scrollLeft+document.documentElement.scrollLeft);a.i=a.clientY+b}}
Bf.prototype.preventDefault=function(){this.event&&(this.event.returnValue=!1,this.event.preventDefault&&this.event.preventDefault())};
Bf.prototype.stopPropagation=function(){this.event&&(this.event.cancelBubble=!0,this.event.stopPropagation&&this.event.stopPropagation())};
Bf.prototype.stopImmediatePropagation=function(){this.event&&(this.event.cancelBubble=!0,this.event.stopImmediatePropagation&&this.event.stopImmediatePropagation())};var jb=y.ytEventsEventsListeners||{};z("ytEventsEventsListeners",jb,void 0);var Df=y.ytEventsEventsCounter||{count:0};z("ytEventsEventsCounter",Df,void 0);
function Ef(a,b,c,d){d=void 0===d?{}:d;a.addEventListener&&("mouseenter"!=b||"onmouseenter"in document?"mouseleave"!=b||"onmouseenter"in document?"mousewheel"==b&&"MozBoxSizing"in document.documentElement.style&&(b="MozMousePixelScroll"):b="mouseout":b="mouseover");return ib(function(e){var f="boolean"===typeof e[4]&&e[4]==!!d,g=Oa(e[4])&&Oa(d)&&ob(e[4],d);return!!e.length&&e[0]==a&&e[1]==b&&e[2]==c&&(f||g)})}
var Ff=Za(function(){var a=!1;try{var b=Object.defineProperty({},"capture",{get:function(){a=!0}});
window.addEventListener("test",null,b)}catch(c){}return a});
function Gf(a,b,c,d){d=void 0===d?{}:d;if(!a||!a.addEventListener&&!a.attachEvent)return"";var e=Ef(a,b,c,d);if(e)return e;e=++Df.count+"";var f=!("mouseenter"!=b&&"mouseleave"!=b||!a.addEventListener||"onmouseenter"in document);var g=f?function(h){h=new Bf(h);if(!Oc(h.relatedTarget,function(k){return k==a}))return h.currentTarget=a,h.type=b,c.call(a,h)}:function(h){h=new Bf(h);
h.currentTarget=a;return c.call(a,h)};
g=rf(g);a.addEventListener?("mouseenter"==b&&f?b="mouseover":"mouseleave"==b&&f?b="mouseout":"mousewheel"==b&&"MozBoxSizing"in document.documentElement.style&&(b="MozMousePixelScroll"),Ff()||"boolean"===typeof d?a.addEventListener(b,g,d):a.addEventListener(b,g,!!d.capture)):a.attachEvent("on"+b,g);jb[e]=[a,b,c,g,d];return e}
function Hf(a){a&&("string"==typeof a&&(a=[a]),E(a,function(b){if(b in jb){var c=jb[b],d=c[0],e=c[1],f=c[3];c=c[4];d.removeEventListener?Ff()||"boolean"===typeof c?d.removeEventListener(e,f,c):d.removeEventListener(e,f,!!c.capture):d.detachEvent&&d.detachEvent("on"+e,f);delete jb[b]}}))}
;var If=window.ytcsi&&window.ytcsi.now?window.ytcsi.now:window.performance&&window.performance.timing&&window.performance.now&&window.performance.timing.navigationStart?function(){return window.performance.timing.navigationStart+window.performance.now()}:function(){return(new Date).getTime()};function Jf(a,b){"function"===typeof a&&(a=rf(a));return window.setTimeout(a,b)}
function Kf(a){window.clearTimeout(a)}
;function Lf(a){this.C=a;this.i=null;this.m=0;this.B=null;this.o=0;this.j=[];for(a=0;4>a;a++)this.j.push(0);this.l=0;this.J=Gf(window,"mousemove",B(this.K,this));a=B(this.F,this);"function"===typeof a&&(a=rf(a));this.L=window.setInterval(a,25)}
C(Lf,L);Lf.prototype.K=function(a){void 0===a.h&&Cf(a);var b=a.h;void 0===a.i&&Cf(a);this.i=new Gc(b,a.i)};
Lf.prototype.F=function(){if(this.i){var a=If();if(0!=this.m){var b=this.B,c=this.i,d=b.x-c.x;b=b.y-c.y;d=Math.sqrt(d*d+b*b)/(a-this.m);this.j[this.l]=.5<Math.abs((d-this.o)/this.o)?1:0;for(c=b=0;4>c;c++)b+=this.j[c]||0;3<=b&&this.C();this.o=d}this.m=a;this.B=this.i;this.l=(this.l+1)%4}};
Lf.prototype.D=function(){window.clearInterval(this.L);Hf(this.J)};function Mf(){}
function Nf(a,b){return Of(a,0,b)}
function Pf(a,b){return Of(a,1,b)}
function Qf(a,b){Of(a,2,b)}
;function Rf(){Mf.apply(this,arguments)}
v(Rf,Mf);function Of(a,b,c){void 0!==c&&Number.isNaN(Number(c))&&(c=void 0);var d=A("yt.scheduler.instance.addJob");return d?d(a,b,c):void 0===c?(a(),NaN):Jf(a,c||0)}
function Sf(a){if(void 0===a||!Number.isNaN(Number(a))){var b=A("yt.scheduler.instance.cancelJob");b?b(a):Kf(a)}}
Rf.prototype.start=function(){var a=A("yt.scheduler.instance.start");a&&a()};
Rf.prototype.pause=function(){var a=A("yt.scheduler.instance.pause");a&&a()};Rf.h||(Rf.h=new Rf);var Tf={};
function Uf(a){var b=void 0===a?{}:a;a=void 0===b.Oa?!0:b.Oa;b=void 0===b.bb?!1:b.bb;if(null==A("_lact",window)){var c=parseInt(F("LACT"),10);c=isFinite(c)?Date.now()-Math.max(c,0):-1;z("_lact",c,window);z("_fact",c,window);-1==c&&Vf();Gf(document,"keydown",Vf);Gf(document,"keyup",Vf);Gf(document,"mousedown",Vf);Gf(document,"mouseup",Vf);a&&(b?Gf(window,"touchmove",function(){Wf("touchmove",200)},{passive:!0}):(Gf(window,"resize",function(){Wf("resize",200)}),Gf(window,"scroll",function(){Wf("scroll",200)})));
new Lf(function(){Wf("mouse",100)});
Gf(document,"touchstart",Vf,{passive:!0});Gf(document,"touchend",Vf,{passive:!0})}}
function Wf(a,b){Tf[a]||(Tf[a]=!0,Pf(function(){Vf();Tf[a]=!1},b))}
function Vf(){null==A("_lact",window)&&Uf();var a=Date.now();z("_lact",a,window);-1==A("_fact",window)&&z("_fact",a,window);(a=A("ytglobal.ytUtilActivityCallback_"))&&a()}
function Xf(){var a=A("_lact",window);return null==a?-1:Math.max(Date.now()-a,0)}
;function Yf(){var a=Zf;A("yt.ads.biscotti.getId_")||z("yt.ads.biscotti.getId_",a,void 0)}
function $f(a){z("yt.ads.biscotti.lastId_",a,void 0)}
;var ag=/^[\w.]*$/,bg={q:!0,search_query:!0};function cg(a,b){b=a.split(b);for(var c={},d=0,e=b.length;d<e;d++){var f=b[d].split("=");if(1==f.length&&f[0]||2==f.length)try{var g=dg(f[0]||""),h=dg(f[1]||"");g in c?Array.isArray(c[g])?gb(c[g],h):c[g]=[c[g],h]:c[g]=h}catch(n){var k=n,l=f[0],p=String(cg);k.args=[{key:l,value:f[1],query:a,method:eg==p?"unchanged":p}];bg.hasOwnProperty(l)||tf(k)}}return c}
var eg=String(cg);function fg(a){var b=[];hb(a,function(c,d){var e=encodeURIComponent(String(d)),f;Array.isArray(c)?f=c:f=[c];E(f,function(g){""==g?b.push(e):b.push(e+"="+encodeURIComponent(String(g)))})});
return b.join("&")}
function gg(a){"?"==a.charAt(0)&&(a=a.substr(1));return cg(a,"&")}
function hg(){var a=window.location.href;return-1!=a.indexOf("?")?(a=(a||"").split("#")[0],a=a.split("?",2),gg(1<a.length?a[1]:a[0])):{}}
function ig(a,b,c){var d=a.split("#",2);a=d[0];d=1<d.length?"#"+d[1]:"";var e=a.split("?",2);a=e[0];e=gg(e[1]||"");for(var f in b)!c&&null!==e&&f in e||(e[f]=b[f]);return hc(a,e)+d}
function jg(a){if(!b)var b=window.location.href;var c=a.match(cc)[1]||null,d=ec(a);c&&d?(a=a.match(cc),b=b.match(cc),a=a[3]==b[3]&&a[1]==b[1]&&a[4]==b[4]):a=d?ec(b)==d&&(Number(b.match(cc)[4]||null)||null)==(Number(a.match(cc)[4]||null)||null):!0;return a}
function dg(a){return a&&a.match(ag)?a:decodeURIComponent(a.replace(/\+/g," "))}
;function kg(a){var b=lg;a=void 0===a?A("yt.ads.biscotti.lastId_")||"":a;var c=Object,d=c.assign,e={};e.dt=Xc;e.flash="0";a:{try{var f=b.h.top.location.href}catch(P){f=2;break a}f=f?f===b.i.location.href?0:1:2}e=(e.frm=f,e);e.u_tz=-(new Date).getTimezoneOffset();var g=void 0===g?K:g;try{var h=g.history.length}catch(P){h=0}e.u_his=h;e.u_java=!!K.navigator&&"unknown"!==typeof K.navigator.javaEnabled&&!!K.navigator.javaEnabled&&K.navigator.javaEnabled();K.screen&&(e.u_h=K.screen.height,e.u_w=K.screen.width,
e.u_ah=K.screen.availHeight,e.u_aw=K.screen.availWidth,e.u_cd=K.screen.colorDepth);K.navigator&&K.navigator.plugins&&(e.u_nplug=K.navigator.plugins.length);K.navigator&&K.navigator.mimeTypes&&(e.u_nmime=K.navigator.mimeTypes.length);h=b.h;try{var k=h.screenX;var l=h.screenY}catch(P){}try{var p=h.outerWidth;var n=h.outerHeight}catch(P){}try{var r=h.innerWidth;var q=h.innerHeight}catch(P){}try{var D=h.screenLeft;var I=h.screenTop}catch(P){}try{r=h.innerWidth,q=h.innerHeight}catch(P){}try{var J=h.screen.availWidth;
var ba=h.screen.availTop}catch(P){}k=[D,I,k,l,J,ba,p,n,r,q];l=b.h.top;try{var U=(l||window).document,O="CSS1Compat"==U.compatMode?U.documentElement:U.body;var oa=(new Hc(O.clientWidth,O.clientHeight)).round()}catch(P){oa=new Hc(-12245933,-12245933)}U=oa;oa={};O=new id;y.SVGElement&&y.document.createElementNS&&O.set(0);l=Tc();l["allow-top-navigation-by-user-activation"]&&O.set(1);l["allow-popups-to-escape-sandbox"]&&O.set(2);y.crypto&&y.crypto.subtle&&O.set(3);y.TextDecoder&&y.TextEncoder&&O.set(4);
O=jd(O);oa.bc=O;oa.bih=U.height;oa.biw=U.width;oa.brdim=k.join();b=b.i;b=(oa.vis={visible:1,hidden:2,prerender:3,preview:4,unloaded:5}[b.visibilityState||b.webkitVisibilityState||b.mozVisibilityState||""]||0,oa.wgl=!!K.WebGLRenderingContext,oa);c=d.call(c,e,b);c.ca_type="image";a&&(c.bid=a);return c}
var lg=new function(){var a=window.document;this.h=window;this.i=a};
z("yt.ads_.signals_.getAdSignalsString",function(a){return fg(kg(a))},void 0);var mg="XMLHttpRequest"in y?function(){return new XMLHttpRequest}:null;
function ng(){if(!mg)return null;var a=mg();return"open"in a?a:null}
function og(a){switch(a&&"status"in a?a.status:-1){case 200:case 201:case 202:case 203:case 204:case 205:case 206:case 304:return!0;default:return!1}}
;var pg={Authorization:"AUTHORIZATION","X-Goog-Visitor-Id":"SANDBOXED_VISITOR_ID","X-Youtube-Chrome-Connected":"CHROME_CONNECTED_HEADER","X-YouTube-Client-Name":"INNERTUBE_CONTEXT_CLIENT_NAME","X-YouTube-Client-Version":"INNERTUBE_CONTEXT_CLIENT_VERSION","X-YouTube-Delegation-Context":"INNERTUBE_CONTEXT_SERIALIZED_DELEGATION_CONTEXT","X-YouTube-Device":"DEVICE","X-Youtube-Identity-Token":"ID_TOKEN","X-YouTube-Page-CL":"PAGE_CL","X-YouTube-Page-Label":"PAGE_BUILD_LABEL","X-YouTube-Variants-Checksum":"VARIANTS_CHECKSUM"},
qg="app debugcss debugjs expflag force_ad_params force_ad_encrypted force_viral_ad_response_params forced_experiments innertube_snapshots innertube_goldens internalcountrycode internalipoverride absolute_experiments conditional_experiments sbb sr_bns_address client_dev_root_url".split(" "),rg=!1;
function sg(a,b){b=void 0===b?{}:b;var c=jg(a),d=Q("web_ajax_ignore_global_headers_if_set"),e;for(e in pg){var f=F(pg[e]);!f||!c&&ec(a)||d&&void 0!==b[e]||(b[e]=f)}if(c||!ec(a))b["X-YouTube-Utc-Offset"]=String(-(new Date).getTimezoneOffset());if(c||!ec(a)){try{var g=(new Intl.DateTimeFormat).resolvedOptions().timeZone}catch(h){}g&&(b["X-YouTube-Time-Zone"]=g)}if(c||!ec(a))b["X-YouTube-Ad-Signals"]=fg(kg(void 0));return b}
function tg(a){var b=window.location.search,c=ec(a);Q("debug_handle_relative_url_for_query_forward_killswitch")||c||!jg(a)||(c=document.location.hostname);var d=dc(a.match(cc)[5]||null);d=(c=c&&(c.endsWith("youtube.com")||c.endsWith("youtube-nocookie.com")))&&d&&d.startsWith("/api/");if(!c||d)return a;var e=gg(b),f={};E(qg,function(g){e[g]&&(f[g]=e[g])});
return ig(a,f||{},!1)}
function ug(a,b){var c=b.format||"JSON";a=vg(a,b);var d=wg(a,b),e=!1,f=xg(a,function(k){if(!e){e=!0;h&&Kf(h);var l=og(k),p=null,n=400<=k.status&&500>k.status,r=500<=k.status&&600>k.status;if(l||n||r)p=yg(a,c,k,b.convertToSafeHtml);if(l)a:if(k&&204==k.status)l=!0;else{switch(c){case "XML":l=0==parseInt(p&&p.return_code,10);break a;case "RAW":l=!0;break a}l=!!p}p=p||{};n=b.context||y;l?b.onSuccess&&b.onSuccess.call(n,k,p):b.onError&&b.onError.call(n,k,p);b.onFinish&&b.onFinish.call(n,k,p)}},b.method,
d,b.headers,b.responseType,b.withCredentials);
if(b.onTimeout&&0<b.timeout){var g=b.onTimeout;var h=Jf(function(){e||(e=!0,f.abort(),Kf(h),g.call(b.context||y,f))},b.timeout)}return f}
function vg(a,b){b.includeDomain&&(a=document.location.protocol+"//"+document.location.hostname+(document.location.port?":"+document.location.port:"")+a);var c=F("XSRF_FIELD_NAME",void 0);if(b=b.urlParams)b[c]&&delete b[c],a=ig(a,b||{},!0);return a}
function wg(a,b){var c=F("XSRF_FIELD_NAME",void 0),d=F("XSRF_TOKEN",void 0),e=b.postBody||"",f=b.postParams,g=F("XSRF_FIELD_NAME",void 0),h;b.headers&&(h=b.headers["Content-Type"]);b.excludeXsrf||ec(a)&&!b.withCredentials&&ec(a)!=document.location.hostname||"POST"!=b.method||h&&"application/x-www-form-urlencoded"!=h||b.postParams&&b.postParams[g]||(f||(f={}),f[c]=d);f&&"string"===typeof e&&(e=gg(e),sb(e,f),e=b.postBodyFormat&&"JSON"==b.postBodyFormat?JSON.stringify(e):gc(e));f=e||f&&!kb(f);!rg&&f&&
"POST"!=b.method&&(rg=!0,sf(Error("AJAX request with postData should use POST")));return e}
function yg(a,b,c,d){var e=null;switch(b){case "JSON":try{var f=c.responseText}catch(g){throw d=Error("Error reading responseText"),d.params=a,tf(d),g;}a=c.getResponseHeader("Content-Type")||"";f&&0<=a.indexOf("json")&&(")]}'\n"===f.substring(0,5)&&(f=f.substring(5)),e=JSON.parse(f));break;case "XML":if(a=(a=c.responseXML)?zg(a):null)e={},E(a.getElementsByTagName("*"),function(g){e[g.tagName]=Ag(g)})}d&&Bg(e);
return e}
function Bg(a){if(Oa(a))for(var b in a){var c;(c="html_content"==b)||(c=b.length-5,c=0<=c&&b.indexOf("_html",c)==c);if(c){c=b;var d=Ub(a[b],null);a[c]=d}else Bg(a[b])}}
function zg(a){return a?(a=("responseXML"in a?a.responseXML:a).getElementsByTagName("root"))&&0<a.length?a[0]:null:null}
function Ag(a){var b="";E(a.childNodes,function(c){b+=c.nodeValue});
return b}
function xg(a,b,c,d,e,f,g){function h(){4==(k&&"readyState"in k?k.readyState:0)&&b&&rf(b)(k)}
c=void 0===c?"GET":c;d=void 0===d?"":d;var k=ng();if(!k)return null;"onloadend"in k?k.addEventListener("loadend",h,!1):k.onreadystatechange=h;Q("debug_forward_web_query_parameters")&&(a=tg(a));k.open(c,a,!0);f&&(k.responseType=f);g&&(k.withCredentials=!0);c="POST"==c&&(void 0===window.FormData||!(d instanceof FormData));if(e=sg(a,e))for(var l in e)k.setRequestHeader(l,e[l]),"content-type"==l.toLowerCase()&&(c=!1);c&&k.setRequestHeader("Content-Type","application/x-www-form-urlencoded");k.send(d);
return k}
;var Cg=zc||Ac;function Dg(a){var b=Pb;return b?0<=b.toLowerCase().indexOf(a):!1}
;var Eg={},Fg=0;
function Gg(a,b,c,d,e){e=void 0===e?"":e;if(a)if(c&&!Dg("cobalt")){if(a){a instanceof Hb||(a="object"==typeof a&&a.X?a.W():String(a),Mb.test(a)?a=new Hb(a,Ib):(a=String(a),a=a.replace(/(%0A|%0D)/g,""),a=(b=a.match(Lb))&&Kb.test(b[1])?new Hb(a,Ib):null));a=Jb(a||Ob);if("about:invalid#zClosurez"===a||a.startsWith("data"))a="";else{if(!(a instanceof Sb)){b="object"==typeof a;var f=null;b&&a.ma&&(f=a.ja());a=Ub(zb(b&&a.X?a.W():String(a)),f)}a instanceof Sb&&a.constructor===Sb?a=a.h:(Ma(a),a="type_error:SafeHtml");
a=encodeURIComponent(String(xe(a.toString())))}/^[\s\xa0]*$/.test(a)||(a=Lc("IFRAME",{src:'javascript:"<body><img src=\\""+'+a+'+"\\"></body>"',style:"display:none"}),(9==a.nodeType?a:a.ownerDocument||a.document).body.appendChild(a))}}else if(e)xg(a,b,"POST",e,d);else if(F("USE_NET_AJAX_FOR_PING_TRANSPORT",!1)||d)xg(a,b,"GET","",d);else{b:{try{var g=new Ya({url:a});if(g.j&&g.i||g.l){var h=dc(a.match(cc)[5]||null),k;if(!(k=!h||!h.endsWith("/aclk"))){var l=a.search(ic);d:{for(c=0;0<=(c=a.indexOf("ri",
c))&&c<l;){var p=a.charCodeAt(c-1);if(38==p||63==p){var n=a.charCodeAt(c+2);if(!n||61==n||38==n||35==n){var r=c;break d}}c+=3}r=-1}if(0>r)var q=null;else{var D=a.indexOf("&",r);if(0>D||D>l)D=l;r+=3;q=decodeURIComponent(a.substr(r,D-r).replace(/\+/g," "))}k="1"!==q}f=!k;break b}}catch(I){}f=!1}f?Hg(a)?(b&&b(),f=!0):f=!1:f=!1;f||Ig(a,b)}}
function Jg(a){var b=void 0===b?"":b;Hg(a,b)||Gg(a,void 0,void 0,void 0,b)}
function Hg(a,b){try{if(window.navigator&&window.navigator.sendBeacon&&window.navigator.sendBeacon(a,void 0===b?"":b))return!0}catch(c){}return!1}
function Ig(a,b){var c=new Image,d=""+Fg++;Eg[d]=c;c.onload=c.onerror=function(){b&&Eg[d]&&b();delete Eg[d]};
c.src=a}
;var Kg=y.ytPubsubPubsubInstance||new M,Lg=y.ytPubsubPubsubSubscribedKeys||{},Mg=y.ytPubsubPubsubTopicToKeys||{},Ng=y.ytPubsubPubsubIsSynchronous||{};function Og(a,b){var c=Pg();if(c&&b){var d=c.subscribe(a,function(){var e=arguments;var f=function(){Lg[d]&&b.apply&&"function"==typeof b.apply&&b.apply(window,e)};
try{Ng[a]?f():Jf(f,0)}catch(g){sf(g)}},void 0);
Lg[d]=!0;Mg[a]||(Mg[a]=[]);Mg[a].push(d);return d}return 0}
function Qg(a){var b=Pg();b&&("number"===typeof a?a=[a]:"string"===typeof a&&(a=[parseInt(a,10)]),E(a,function(c){b.unsubscribeByKey(c);delete Lg[c]}))}
function Rg(a,b){var c=Pg();c&&c.publish.apply(c,arguments)}
function Sg(a){var b=Pg();if(b)if(b.clear(a),a)Tg(a);else for(var c in Mg)Tg(c)}
function Pg(){return y.ytPubsubPubsubInstance}
function Tg(a){Mg[a]&&(a=Mg[a],E(a,function(b){Lg[b]&&delete Lg[b]}),a.length=0)}
M.prototype.subscribe=M.prototype.subscribe;M.prototype.unsubscribeByKey=M.prototype.Y;M.prototype.publish=M.prototype.S;M.prototype.clear=M.prototype.clear;z("ytPubsubPubsubInstance",Kg,void 0);z("ytPubsubPubsubTopicToKeys",Mg,void 0);z("ytPubsubPubsubIsSynchronous",Ng,void 0);z("ytPubsubPubsubSubscribedKeys",Lg,void 0);var Ug=window,R=Ug.ytcsi&&Ug.ytcsi.now?Ug.ytcsi.now:Ug.performance&&Ug.performance.timing&&Ug.performance.now&&Ug.performance.timing.navigationStart?function(){return Ug.performance.timing.navigationStart+Ug.performance.now()}:function(){return(new Date).getTime()};var Vg=xf("initial_gel_batch_timeout",1E3),Wg=Math.pow(2,16)-1,Xg=null,Yg=0,Zg=void 0,$g=0,ah=0,bh=0,ch=!0,dh=y.ytLoggingTransportGELQueue_||new Map;z("ytLoggingTransportGELQueue_",dh,void 0);var eh=y.ytLoggingTransportTokensToCttTargetIds_||{};z("ytLoggingTransportTokensToCttTargetIds_",eh,void 0);
function fh(a,b){if("log_event"===a.endpoint){var c="";a.ea?c="visitorOnlyApprovedKey":a.G&&(eh[a.G.token]=gh(a.G),c=a.G.token);var d=dh.get(c)||[];dh.set(c,d);d.push(a.payload);b&&(Zg=new b);a=xf("tvhtml5_logging_max_batch")||xf("web_logging_max_batch")||100;b=R();d.length>=a?hh({writeThenSend:!0}):10<=b-bh&&(ih(),bh=b)}}
function jh(a,b){if("log_event"===a.endpoint){var c="";a.ea?c="visitorOnlyApprovedKey":a.G&&(eh[a.G.token]=gh(a.G),c=a.G.token);var d=new Map;d.set(c,[a.payload]);b&&(Zg=new b);return new Ee(function(e){Zg&&Zg.isReady()?kh(d,e,{bypassNetworkless:!0}):e()})}}
function hh(a){a=void 0===a?{}:a;new Ee(function(b){Kf($g);Kf(ah);ah=0;Zg&&Zg.isReady()?(kh(dh,b,a),dh.clear()):(ih(),b())})}
function ih(){Q("web_gel_timeout_cap")&&!ah&&(ah=Jf(function(){hh({writeThenSend:!0})},6E4));
Kf($g);var a=F("LOGGING_BATCH_TIMEOUT",xf("web_gel_debounce_ms",1E4));Q("shorten_initial_gel_batch_timeout")&&ch&&(a=Vg);$g=Jf(function(){hh({writeThenSend:!0})},a)}
function kh(a,b,c){var d=Zg;c=void 0===c?{}:c;var e=Math.round(R()),f=a.size;a=u(a);for(var g=a.next();!g.done;g=a.next()){var h=u(g.value);g=h.next().value;var k=h.next().value;h=qb({context:lh(d.h||mh())});h.events=k;(k=eh[g])&&nh(h,g,k);delete eh[g];g="visitorOnlyApprovedKey"===g;oh(h,e,g);Q("send_beacon_before_gel")&&window.navigator&&window.navigator.sendBeacon&&!c.writeThenSend&&Jg("/generate_204");ph(d,"log_event",h,{retry:!0,onSuccess:function(){f--;f||b();Yg=Math.round(R()-e)},
onError:function(){f--;f||b()},
Ba:c,ea:g});ch=!1}}
function oh(a,b,c){a.requestTimeMs=String(b);Q("unsplit_gel_payloads_in_logs")&&(a.unsplitGelPayloadsInLogs=!0);!c&&(b=F("EVENT_ID",void 0))&&((c=F("BATCH_CLIENT_COUNTER",void 0)||0)||(c=Math.floor(Math.random()*Wg/2)),c++,c>Wg&&(c=1),N("BATCH_CLIENT_COUNTER",c),b={serializedEventId:b,clientCounter:String(c)},a.serializedClientEventId=b,Xg&&Yg&&Q("log_gel_rtt_web")&&(a.previousBatchInfo={serializedClientEventId:Xg,roundtripMs:String(Yg)}),Xg=b,Yg=0)}
function nh(a,b,c){if(c.videoId)var d="VIDEO";else if(c.playlistId)d="PLAYLIST";else return;a.credentialTransferTokenTargetId=c;a.context=a.context||{};a.context.user=a.context.user||{};a.context.user.credentialTransferTokens=[{token:b,scope:d}]}
function gh(a){var b={};a.videoId?b.videoId=a.videoId:a.playlistId&&(b.playlistId=a.playlistId);return b}
;var qh=y.ytLoggingGelSequenceIdObj_||{};z("ytLoggingGelSequenceIdObj_",qh,void 0);function rh(a,b,c,d){d=void 0===d?{}:d;var e={},f=Math.round(d.timestamp||R());e.eventTimeMs=f<Number.MAX_SAFE_INTEGER?f:0;e[a]=b;a=Xf();e.context={lastActivityMs:String(d.timestamp||!isFinite(a)?-1:a)};Q("log_sequence_info_on_gel_web")&&d.P&&(a=e.context,b=d.P,qh[b]=b in qh?qh[b]+1:0,a.sequence={index:qh[b],groupKey:b},d.Ma&&delete qh[d.P]);(d.Qk?jh:fh)({endpoint:"log_event",payload:e,G:d.G,ea:d.ea},c)}
;function sh(){if(!y.matchMedia)return"WEB_DISPLAY_MODE_UNKNOWN";try{return y.matchMedia("(display-mode: standalone)").matches?"WEB_DISPLAY_MODE_STANDALONE":y.matchMedia("(display-mode: minimal-ui)").matches?"WEB_DISPLAY_MODE_MINIMAL_UI":y.matchMedia("(display-mode: fullscreen)").matches?"WEB_DISPLAY_MODE_FULLSCREEN":y.matchMedia("(display-mode: browser)").matches?"WEB_DISPLAY_MODE_BROWSER":"WEB_DISPLAY_MODE_UNKNOWN"}catch(a){return"WEB_DISPLAY_MODE_UNKNOWN"}}
;function th(a,b,c,d,e){ed.set(""+a,b,{oa:c,path:"/",domain:void 0===d?"youtube.com":d,secure:void 0===e?!1:e})}
;var uh=A("ytglobal.prefsUserPrefsPrefs_")||{};z("ytglobal.prefsUserPrefsPrefs_",uh,void 0);function vh(){this.h=F("ALT_PREF_COOKIE_NAME","PREF");this.i=F("ALT_PREF_COOKIE_DOMAIN","youtube.com");var a=ed.get(""+this.h,void 0);if(a){a=decodeURIComponent(a).split("&");for(var b=0;b<a.length;b++){var c=a[b].split("="),d=c[0];(c=c[1])&&(uh[d]=c.toString())}}}
vh.prototype.get=function(a,b){wh(a);xh(a);a=void 0!==uh[a]?uh[a].toString():null;return null!=a?a:b?b:""};
vh.prototype.set=function(a,b){wh(a);xh(a);if(null==b)throw Error("ExpectedNotNull");uh[a]=b.toString()};
vh.prototype.remove=function(a){wh(a);xh(a);delete uh[a]};
vh.prototype.clear=function(){for(var a in uh)delete uh[a]};
function xh(a){if(/^f([1-9][0-9]*)$/.test(a))throw Error("ExpectedRegexMatch: "+a);}
function wh(a){if(!/^\w+$/.test(a))throw Error("ExpectedRegexMismatch: "+a);}
function yh(a){a=void 0!==uh[a]?uh[a].toString():null;return null!=a&&/^[A-Fa-f0-9]+$/.test(a)?parseInt(a,16):null}
La(vh);var zh={bluetooth:"CONN_DISCO",cellular:"CONN_CELLULAR_UNKNOWN",ethernet:"CONN_WIFI",none:"CONN_NONE",wifi:"CONN_WIFI",wimax:"CONN_CELLULAR_4G",other:"CONN_UNKNOWN",unknown:"CONN_UNKNOWN","slow-2g":"CONN_CELLULAR_2G","2g":"CONN_CELLULAR_2G","3g":"CONN_CELLULAR_3G","4g":"CONN_CELLULAR_4G"},Ah={"slow-2g":"EFFECTIVE_CONNECTION_TYPE_SLOW_2G","2g":"EFFECTIVE_CONNECTION_TYPE_2G","3g":"EFFECTIVE_CONNECTION_TYPE_3G","4g":"EFFECTIVE_CONNECTION_TYPE_4G"};
function Bh(){var a=y.navigator;return a?a.connection:void 0}
;function Ch(){return"INNERTUBE_API_KEY"in of&&"INNERTUBE_API_VERSION"in of}
function mh(){return{innertubeApiKey:F("INNERTUBE_API_KEY",void 0),innertubeApiVersion:F("INNERTUBE_API_VERSION",void 0),Pa:F("INNERTUBE_CONTEXT_CLIENT_CONFIG_INFO"),Qa:F("INNERTUBE_CONTEXT_CLIENT_NAME","WEB"),innertubeContextClientVersion:F("INNERTUBE_CONTEXT_CLIENT_VERSION",void 0),Sa:F("INNERTUBE_CONTEXT_HL",void 0),Ra:F("INNERTUBE_CONTEXT_GL",void 0),Ta:F("INNERTUBE_HOST_OVERRIDE",void 0)||"",Va:!!F("INNERTUBE_USE_THIRD_PARTY_AUTH",!1),Ua:!!F("INNERTUBE_OMIT_API_KEY_WHEN_AUTH_HEADER_IS_PRESENT",
!1),appInstallData:F("SERIALIZED_CLIENT_CONFIG_DATA",void 0)}}
function lh(a){var b={client:{hl:a.Sa,gl:a.Ra,clientName:a.Qa,clientVersion:a.innertubeContextClientVersion,configInfo:a.Pa}},c=y.devicePixelRatio;c&&1!=c&&(b.client.screenDensityFloat=String(c));c=F("EXPERIMENTS_TOKEN","");""!==c&&(b.client.experimentsToken=c);c=[];var d=F("EXPERIMENTS_FORCED_FLAGS",{});for(e in d)c.push({key:e,value:String(d[e])});var e=F("EXPERIMENT_FLAGS",{});for(var f in e)f.startsWith("force_")&&void 0===d[f]&&c.push({key:f,value:String(e[f])});0<c.length&&(b.request={internalExperimentFlags:c});
f=b.client.clientName;if("WEB"===f||"MWEB"===f||1===f||2===f){if(!Q("web_include_display_mode_killswitch")){var g;b.client.mainAppWebInfo=null!=(g=b.client.mainAppWebInfo)?g:{};b.client.mainAppWebInfo.webDisplayMode=sh()}}else if(g=b.client.clientName,("WEB_REMIX"===g||76===g)&&!Q("music_web_display_mode_killswitch")){var h;b.client.Aa=null!=(h=b.client.Aa)?h:{};b.client.Aa.webDisplayMode=sh()}a.appInstallData&&(b.client.configInfo=b.client.configInfo||{},b.client.configInfo.appInstallData=a.appInstallData);
F("DELEGATED_SESSION_ID")&&!Q("pageid_as_header_web")&&(b.user={onBehalfOfUser:F("DELEGATED_SESSION_ID")});a:{if(h=Bh()){a=zh[h.type||"unknown"]||"CONN_UNKNOWN";h=zh[h.effectiveType||"unknown"]||"CONN_UNKNOWN";"CONN_CELLULAR_UNKNOWN"===a&&"CONN_UNKNOWN"!==h&&(a=h);if("CONN_UNKNOWN"!==a)break a;if("CONN_UNKNOWN"!==h){a=h;break a}}a=void 0}a&&(b.client.connectionType=a);Q("web_log_effective_connection_type")&&(a=Bh(),a=null!==a&&void 0!==a&&a.effectiveType?Ah.hasOwnProperty(a.effectiveType)?Ah[a.effectiveType]:
"EFFECTIVE_CONNECTION_TYPE_UNKNOWN":void 0,a&&(b.client.effectiveConnectionType=a));a=Object;h=a.assign;g=b.client;f={};e=u(Object.entries(gg(F("DEVICE",""))));for(c=e.next();!c.done;c=e.next())d=u(c.value),c=d.next().value,d=d.next().value,"cbrand"===c?f.deviceMake=d:"cmodel"===c?f.deviceModel=d:"cbr"===c?f.browserName=d:"cbrver"===c?f.browserVersion=d:"cos"===c?f.osName=d:"cosver"===c?f.osVersion=d:"cplatform"===c&&(f.platform=d);b.client=h.call(a,g,f);return b}
function Dh(a,b,c){c=void 0===c?{}:c;var d={"X-Goog-Visitor-Id":c.visitorData||F("VISITOR_DATA","")};if(b&&b.includes("www.youtube-nocookie.com"))return d;(b=c.Hk||F("AUTHORIZATION"))||(a?b="Bearer "+A("gapi.auth.getToken")().Gk:b=hd([]));b&&(d.Authorization=b,d["X-Goog-AuthUser"]=F("SESSION_INDEX",0),Q("pageid_as_header_web")&&(d["X-Goog-PageId"]=F("DELEGATED_SESSION_ID")));return d}
;function Eh(a){a=Object.assign({},a);delete a.Authorization;var b=hd();if(b){var c=new zd;c.update(F("INNERTUBE_API_KEY",void 0));c.update(b);a.hash=Ec(c.digest())}return a}
;function Fh(a){var b=new ff;(b=b.isAvailable()?a?new mf(b,a):b:null)||(a=new gf(a||"UserDataSharedStore"),b=a.isAvailable()?a:null);this.h=(a=b)?new bf(a):null;this.i=document.domain||window.location.hostname}
Fh.prototype.set=function(a,b,c,d){c=c||31104E3;this.remove(a);if(this.h)try{this.h.set(a,b,Date.now()+1E3*c);return}catch(f){}var e="";if(d)try{e=escape(xe(b))}catch(f){return}else e=escape(b);th(a,e,c,this.i)};
Fh.prototype.get=function(a,b){var c=void 0,d=!this.h;if(!d)try{c=this.h.get(a)}catch(e){d=!0}if(d&&(c=ed.get(""+a,void 0))&&(c=unescape(c),b))try{c=JSON.parse(c)}catch(e){this.remove(a),c=void 0}return c};
Fh.prototype.remove=function(a){this.h&&this.h.remove(a);var b=this.i;ed.remove(""+a,"/",void 0===b?"youtube.com":b)};var Gh;function Hh(){Gh||(Gh=new Fh("yt.innertube"));return Gh}
function Ih(a,b,c,d){if(d)return null;d=Hh().get("nextId",!0)||1;var e=Hh().get("requests",!0)||{};e[d]={method:a,request:b,authState:Eh(c),requestTime:Math.round(R())};Hh().set("nextId",d+1,86400,!0);Hh().set("requests",e,86400,!0);return d}
function Jh(a){var b=Hh().get("requests",!0)||{};delete b[a];Hh().set("requests",b,86400,!0)}
function Kh(a){var b=Hh().get("requests",!0);if(b){for(var c in b){var d=b[c];if(!(6E4>Math.round(R())-d.requestTime)){var e=d.authState,f=Eh(Dh(!1));ob(e,f)&&(e=d.request,"requestTimeMs"in e&&(e.requestTimeMs=Math.round(R())),ph(a,d.method,e,{}));delete b[c]}}Hh().set("requests",b,86400,!0)}}
;function Lh(a,b){this.version=a;this.args=b}
;function Mh(a,b){this.topic=a;this.h=b}
Mh.prototype.toString=function(){return this.topic};var Nh=A("ytPubsub2Pubsub2Instance")||new M;M.prototype.subscribe=M.prototype.subscribe;M.prototype.unsubscribeByKey=M.prototype.Y;M.prototype.publish=M.prototype.S;M.prototype.clear=M.prototype.clear;z("ytPubsub2Pubsub2Instance",Nh,void 0);var Oh=A("ytPubsub2Pubsub2SubscribedKeys")||{};z("ytPubsub2Pubsub2SubscribedKeys",Oh,void 0);var Ph=A("ytPubsub2Pubsub2TopicToKeys")||{};z("ytPubsub2Pubsub2TopicToKeys",Ph,void 0);var Qh=A("ytPubsub2Pubsub2IsAsync")||{};z("ytPubsub2Pubsub2IsAsync",Qh,void 0);
z("ytPubsub2Pubsub2SkipSubKey",null,void 0);function Rh(a,b){var c=Sh();c&&c.publish.call(c,a.toString(),a,b)}
function Th(a){var b=Uh,c=Sh();if(!c)return 0;var d=c.subscribe(b.toString(),function(e,f){var g=A("ytPubsub2Pubsub2SkipSubKey");g&&g==d||(g=function(){if(Oh[d])try{if(f&&b instanceof Mh&&b!=e)try{var h=b.h,k=f;if(!k.args||!k.version)throw Error("yt.pubsub2.Data.deserialize(): serializedData is incomplete.");try{if(!h.R){var l=new h;h.R=l.version}var p=h.R}catch(n){}if(!p||k.version!=p)throw Error("yt.pubsub2.Data.deserialize(): serializedData version is incompatible.");try{f=Reflect.construct(h,
fb(k.args))}catch(n){throw n.message="yt.pubsub2.Data.deserialize(): "+n.message,n;}}catch(n){throw n.message="yt.pubsub2.pubsub2 cross-binary conversion error for "+b.toString()+": "+n.message,n;}a.call(window,f)}catch(n){sf(n)}},Qh[b.toString()]?A("yt.scheduler.instance")?Pf(g):Jf(g,0):g())});
Oh[d]=!0;Ph[b.toString()]||(Ph[b.toString()]=[]);Ph[b.toString()].push(d);return d}
function Vh(){var a=Wh,b=Th(function(c){a.apply(void 0,arguments);Xh(b)});
return b}
function Xh(a){var b=Sh();b&&("number"===typeof a&&(a=[a]),E(a,function(c){b.unsubscribeByKey(c);delete Oh[c]}))}
function Sh(){return A("ytPubsub2Pubsub2Instance")}
;function Yh(){}
;var Zh=[],$h=!1;function ai(a){$h||(Zh.push({type:"ERROR",payload:a}),10<Zh.length&&Zh.shift())}
function bi(a,b){$h||(Zh.push({type:"EVENT",eventType:a,payload:b}),10<Zh.length&&Zh.shift())}
;var ci=function(){var a;return function(){a||(a=new Fh("ytidb"));return a}}();
function di(){var a;return null===(a=ci())||void 0===a?void 0:a.get("LAST_RESULT_ENTRY_KEY",!0)}
function ei(a,b,c){this.h=void 0===a?!1:a;this.failureMessage=b;this.j=c;(a=di())||(a={createdTimestampMs:R(),isSupported:this.h,resultCount:0,hasSucceededOnce:this.h});this.i=a;var d;if(fi()){var e;this.i.isSupported===this.h?e=Object.assign(Object.assign({},this.i),{resultCount:this.i.resultCount+1}):e={isSupported:this.h,resultCount:1,createdTimestampMs:R(),hasSucceededOnce:this.i.hasSucceededOnce||this.h};null===(d=ci())||void 0===d?void 0:d.set("LAST_RESULT_ENTRY_KEY",e,2592E3,!0)}}
function gi(a,b){return new ei(!1,a instanceof Error?a.message:"",void 0===b?!1:b)}
ei.prototype.isSupported=function(){return this.h};
ei.prototype.log=function(){fi()&&bi("IS_SUPPORTED_COMPLETED",{isSupported:this.h,lastIsSupported:this.i.isSupported,failureMessage:this.failureMessage,sameResultCount:this.i.resultCount,sameResultDurationMs:Math.floor(R()-this.i.createdTimestampMs),canDetectDataOnFailure:this.j})};
function fi(){var a;return!!(Q("ytidb_analyze_is_supported")&&(null===(a=ci())||void 0===a?0:a.h))}
;function hi(a,b){for(var c=[],d=1;d<arguments.length;++d)c[d-1]=arguments[d];d=Error.call(this,a);this.message=d.message;"stack"in d&&(this.stack=d.stack);this.args=[].concat(c instanceof Array?c:ha(u(c)))}
v(hi,Error);function ii(a){if(0<=a.indexOf(":"))throw Error("Database name cannot contain ':'");}
function ji(a){return a.substr(0,a.indexOf(":"))||a}
;var ki={},li=(ki.AUTH_INVALID="No user identifier specified.",ki.EXPLICIT_ABORT="Transaction was explicitly aborted.",ki.IDB_NOT_SUPPORTED="IndexedDB is not supported.",ki.MISSING_OBJECT_STORE="Object store not created.",ki.UNKNOWN_ABORT="Transaction was aborted for unknown reasons.",ki.QUOTA_EXCEEDED="The current transaction exceeded its quota limitations.",ki.QUOTA_MAYBE_EXCEEDED="The current transaction may have failed because of exceeding quota limitations.",ki.EXECUTE_TRANSACTION_ON_CLOSED_DB=
"Can't start a transaction on a closed database",ki),mi={},ni=(mi.AUTH_INVALID="ERROR",mi.EXECUTE_TRANSACTION_ON_CLOSED_DB="WARNING",mi.EXPLICIT_ABORT="IGNORED",mi.IDB_NOT_SUPPORTED="ERROR",mi.MISSING_OBJECT_STORE="ERROR",mi.QUOTA_EXCEEDED="WARNING",mi.QUOTA_MAYBE_EXCEEDED="WARNING",mi.UNKNOWN_ABORT="WARNING",mi),oi={},pi=(oi.AUTH_INVALID=!1,oi.EXECUTE_TRANSACTION_ON_CLOSED_DB=!1,oi.EXPLICIT_ABORT=!1,oi.IDB_NOT_SUPPORTED=!1,oi.MISSING_OBJECT_STORE=!1,oi.QUOTA_EXCEEDED=!1,oi.QUOTA_MAYBE_EXCEEDED=!0,
oi.UNKNOWN_ABORT=!0,oi);function S(a,b,c,d,e){b=void 0===b?{}:b;c=void 0===c?li[a]:c;d=void 0===d?ni[a]:d;e=void 0===e?pi[a]:e;hi.call(this,c,Object.assign({name:"YtIdbKnownError",isSw:void 0===self.document,isIframe:self!==self.top,type:a},b));this.type=a;this.message=c;this.level=d;this.h=e;Object.setPrototypeOf(this,S.prototype)}
v(S,hi);function qi(a){S.call(this,"MISSING_OBJECT_STORE",{Lk:a},li.MISSING_OBJECT_STORE);Object.setPrototypeOf(this,qi.prototype)}
v(qi,S);var ri=["The database connection is closing","Can't start a transaction on a closed database","A mutation operation was attempted on a database that did not allow mutations"];
function si(a,b,c){b=ji(b);var d=a instanceof Error?a:Error("Unexpected error: "+a);if(d instanceof S)return d;if("QuotaExceededError"===d.name)return new S("QUOTA_EXCEEDED",{objectStoreNames:c,dbName:b});if(Bc&&"UnknownError"===d.name)return new S("QUOTA_MAYBE_EXCEEDED",{objectStoreNames:c,dbName:b});if("InvalidStateError"===d.name&&ri.some(function(e){return d.message.includes(e)}))return new S("EXECUTE_TRANSACTION_ON_CLOSED_DB",{objectStoreNames:c,
dbName:b});if("AbortError"===d.name)return new S("UNKNOWN_ABORT",{objectStoreNames:c,dbName:b},d.message);d.args=[{name:"IdbError",Mk:d.name,dbName:b,objectStoreNames:c}];d.level="WARNING";return d}
;function ti(a){if(!a)throw Error();throw a;}
function ui(a){return a}
function T(a){function b(e){if("PENDING"===d.state.status){d.state={status:"REJECTED",reason:e};e=u(d.onRejected);for(var f=e.next();!f.done;f=e.next())f=f.value,f()}}
function c(e){if("PENDING"===d.state.status){d.state={status:"FULFILLED",value:e};e=u(d.h);for(var f=e.next();!f.done;f=e.next())f=f.value,f()}}
var d=this;this.i=a;this.state={status:"PENDING"};this.h=[];this.onRejected=[];try{this.i(c,b)}catch(e){b(e)}}
T.all=function(a){return new T(function(b,c){var d=[],e=a.length;0===e&&b(d);for(var f={U:0};f.U<a.length;f={U:f.U},++f.U)vi(T.resolve(a[f.U]).then(function(g){return function(h){d[g.U]=h;e--;0===e&&b(d)}}(f)),function(g){c(g)})})};
T.resolve=function(a){return new T(function(b,c){a instanceof T?a.then(b,c):b(a)})};
T.reject=function(a){return new T(function(b,c){c(a)})};
T.prototype.then=function(a,b){var c=this,d=null!==a&&void 0!==a?a:ui,e=null!==b&&void 0!==b?b:ti;return new T(function(f,g){"PENDING"===c.state.status?(c.h.push(function(){wi(c,c,d,f,g)}),c.onRejected.push(function(){xi(c,c,e,f,g)})):"FULFILLED"===c.state.status?wi(c,c,d,f,g):"REJECTED"===c.state.status&&xi(c,c,e,f,g)})};
function vi(a,b){a.then(void 0,b)}
function wi(a,b,c,d,e){try{if("FULFILLED"!==a.state.status)throw Error("calling handleResolve before the promise is fulfilled.");var f=c(a.state.value);f instanceof T?yi(a,b,f,d,e):d(f)}catch(g){e(g)}}
function xi(a,b,c,d,e){try{if("REJECTED"!==a.state.status)throw Error("calling handleReject before the promise is rejected.");var f=c(a.state.reason);f instanceof T?yi(a,b,f,d,e):d(f)}catch(g){e(g)}}
function yi(a,b,c,d,e){b===c?e(new TypeError("Circular promise chain detected.")):c.then(function(f){f instanceof T?yi(a,b,f,d,e):d(f)},function(f){e(f)})}
;function zi(a,b,c){function d(){c(a.error);f()}
function e(){b(a.result);f()}
function f(){try{a.removeEventListener("success",e),a.removeEventListener("error",d)}catch(g){}}
a.addEventListener("success",e);a.addEventListener("error",d)}
function Ai(a){return new Promise(function(b,c){zi(a,b,c)})}
function V(a){return new T(function(b,c){zi(a,b,c)})}
;function Bi(a,b){return new T(function(c,d){function e(){var f=a?b(a):null;f?f.then(function(g){a=g;e()},d):c()}
e()})}
;function Ci(a){return new Promise(function(b){Qf(function(){b()},a)})}
function Di(a,b){this.h=a;this.options=b;this.transactionCount=0;this.j=Math.round(R());this.i=!1}
m=Di.prototype;m.add=function(a,b,c){return Ei(this,[a],{mode:"readwrite",I:!0},function(d){return Fi(d,a).add(b,c)})};
m.clear=function(a){return Ei(this,[a],{mode:"readwrite",I:!0},function(b){return Fi(b,a).clear()})};
m.close=function(){var a;this.h.close();(null===(a=this.options)||void 0===a?0:a.closed)&&this.options.closed()};
m.count=function(a,b){return Ei(this,[a],{mode:"readonly",I:!0},function(c){return Fi(c,a).count(b)})};
function Gi(a,b,c){a=a.h.createObjectStore(b,c);return new Hi(a)}
m.delete=function(a,b){return Ei(this,[a],{mode:"readwrite",I:!0},function(c){return Fi(c,a).delete(b)})};
m.get=function(a,b){return Ei(this,[a],{mode:"readonly",I:!0},function(c){return Fi(c,a).get(b)})};
function Ii(a,b,c,d){return Ei(a,[b],{mode:"readwrite",I:!0},function(e){e=Fi(e,b);return V(e.h.put(c,d))})}
function Ei(a,b,c,d){return H(a,function f(){var g=this,h,k,l,p,n,r,q,D,I,J,ba,U,O,oa;return x(f,function(P){switch(P.h){case 1:var mb={mode:"readonly",I:!1};"string"===typeof c?mb.mode=c:mb=c;h=mb;g.transactionCount++;k=Q("ytidb_transaction_exponential_backoff_retries");l=h.I?xf("ytidb_transaction_try_count",1):1;p=500;n=0;case 2:if(r){P.A(3);break}n++;q=Math.round(R());ta(P,4);D=g.h.transaction(b,h.mode);mb=new Ji(D);mb=Ki(mb,d);return w(P,mb,6);case 6:return I=P.i,J=Math.round(R()),Li(g,q,J,n,
void 0,b.join(),h),P.return(I);case 4:ba=ua(P);U=Math.round(R());O=si(ba,g.h.name,b.join());if((oa=O instanceof S&&!O.h)||n>=l){Li(g,q,U,n,O,b.join(),h);r=O;P.A(2);break}if(!k){P.A(2);break}return w(P,Ci(p),9);case 9:p*=2;P.A(2);break;case 3:return P.return(Promise.reject(r))}})})}
function Li(a,b,c,d,e,f,g){b=c-b;e?(e instanceof S&&("QUOTA_EXCEEDED"===e.type||"QUOTA_MAYBE_EXCEEDED"===e.type)&&bi("QUOTA_EXCEEDED",{dbName:ji(a.h.name),objectStoreNames:f,transactionCount:a.transactionCount,transactionMode:g.mode}),e instanceof S&&"UNKNOWN_ABORT"===e.type&&(bi("TRANSACTION_UNEXPECTEDLY_ABORTED",{objectStoreNames:f,transactionDuration:b,transactionCount:a.transactionCount,dbDuration:c-a.j}),a.i=!0),Mi(a,!1,d,f,b),ai(e)):Mi(a,!0,d,f,b)}
function Mi(a,b,c,d,e){bi("TRANSACTION_ENDED",{objectStoreNames:d,connectionHasUnknownAbortedTransaction:a.i,duration:e,isSuccessful:b,tryCount:c})}
function Hi(a){this.h=a}
m=Hi.prototype;m.add=function(a,b){return V(this.h.add(a,b))};
m.clear=function(){return V(this.h.clear()).then(function(){})};
m.count=function(a){return V(this.h.count(a))};
function Ni(a,b){return Oi(a,{query:b},function(c){return c.delete().then(function(){return c.continue()})}).then(function(){})}
m.delete=function(a){return a instanceof IDBKeyRange?Ni(this,a):V(this.h.delete(a))};
m.get=function(a){return V(this.h.get(a))};
m.index=function(a){return new Pi(this.h.index(a))};
m.getName=function(){return this.h.name};
function Oi(a,b,c){a=a.h.openCursor(b.query,b.direction);return Qi(a).then(function(d){return Bi(d,c)})}
function Ji(a){var b=this;this.h=a;this.i=new Map;this.aborted=!1;this.done=new Promise(function(c,d){b.h.addEventListener("complete",function(){c()});
b.h.addEventListener("error",function(e){e.currentTarget===e.target&&d(b.h.error)});
b.h.addEventListener("abort",function(){var e=b.h.error;if(e)d(e);else if(!b.aborted){e=S;for(var f=b.h.objectStoreNames,g=[],h=0;h<f.length;h++){var k=f.item(h);if(null===k)throw Error("Invariant: item in DOMStringList is null");g.push(k)}e=new e("UNKNOWN_ABORT",{objectStoreNames:g.join(),dbName:b.h.db.name,mode:b.h.mode});d(e)}})})}
function Ki(a,b){var c=new Promise(function(d,e){vi(b(a).then(function(f){a.commit();d(f)}),e)});
return Promise.all([c,a.done]).then(function(d){return u(d).next().value})}
Ji.prototype.abort=function(){this.h.abort();this.aborted=!0;throw new S("EXPLICIT_ABORT");};
Ji.prototype.commit=function(){var a=this.h;a.commit&&!this.aborted&&a.commit()};
function Fi(a,b){b=a.h.objectStore(b);var c=a.i.get(b);c||(c=new Hi(b),a.i.set(b,c));return c}
function Pi(a){this.h=a}
Pi.prototype.count=function(a){return V(this.h.count(a))};
Pi.prototype.delete=function(a){return Ri(this,{query:a},function(b){return b.delete().then(function(){return b.continue()})})};
Pi.prototype.get=function(a){return V(this.h.get(a))};
Pi.prototype.getKey=function(a){return V(this.h.getKey(a))};
function Ri(a,b,c){a=a.h.openCursor(void 0===b.query?null:b.query,void 0===b.direction?"next":b.direction);return Qi(a).then(function(d){return Bi(d,c)})}
function Si(a,b){this.request=a;this.cursor=b}
function Qi(a){return V(a).then(function(b){return null===b?null:new Si(a,b)})}
m=Si.prototype;m.advance=function(a){this.cursor.advance(a);return Qi(this.request)};
m.continue=function(a){this.cursor.continue(a);return Qi(this.request)};
m.delete=function(){return V(this.cursor.delete()).then(function(){})};
m.getKey=function(){return this.cursor.key};
m.getValue=function(){return this.cursor.value};
m.update=function(a){return V(this.cursor.update(a))};function Ti(a,b,c){return H(this,function e(){var f,g,h,k,l,p,n,r,q,D;return x(e,function(I){if(1==I.h)return f=self.indexedDB.open(a,b),g=c,h=g.blocked,k=g.blocking,l=g.nb,p=g.upgrade,n=g.closed,q=function(){r||(r=new Di(f.result,{closed:n}));return r},f.addEventListener("upgradeneeded",function(J){if(null===J.newVersion)throw Error("Invariant: newVersion on IDbVersionChangeEvent is null");
if(null===f.transaction)throw Error("Invariant: transaction on IDbOpenDbRequest is null");J.dataLoss&&"none"!==J.dataLoss&&bi("IDB_DATA_CORRUPTED",{reason:J.dataLossMessage||"unknown reason",dbName:ji(a)});var ba=q(),U=new Ji(f.transaction);p&&p(ba,J.oldVersion,J.newVersion,U)}),h&&f.addEventListener("blocked",function(){h()}),w(I,Ai(f),2);
D=I.i;k&&D.addEventListener("versionchange",function(){k(q())});
D.addEventListener("close",function(){bi("IDB_UNEXPECTEDLY_CLOSED",{dbName:ji(a),dbVersion:D.version});l&&l()});
return I.return(q())})})}
function Ui(a,b,c){c=void 0===c?{}:c;return Ti(a,b,c)}
function Vi(a,b){b=void 0===b?{}:b;return H(this,function d(){var e,f,g;return x(d,function(h){e=self.indexedDB.deleteDatabase(a);f=b;(g=f.blocked)&&e.addEventListener("blocked",function(){g()});
return w(h,Ai(e),0)})})}
;function Wi(a,b){this.name=a;this.options=b;this.j=!1}
Wi.prototype.i=function(a,b,c){c=void 0===c?{}:c;return Ui(a,b,c)};
Wi.prototype.delete=function(a){a=void 0===a?{}:a;return Vi(this.name,a)};
Wi.prototype.open=function(){var a=this;if(!this.h){var b,c=function(){a.h===b&&(a.h=void 0)},d={blocking:function(f){f.close()},
closed:c,nb:c,upgrade:this.options.upgrade},e=function(){return H(a,function g(){var h=this,k,l,p;return x(g,function(n){switch(n.h){case 1:return ta(n,2),w(n,h.i(h.name,h.options.version,d),4);case 4:k=n.i;a:{var r=u(Object.keys(h.options.Ca));for(var q=r.next();!q.done;q=r.next())if(q=q.value,!k.h.objectStoreNames.contains(q)){r=q;break a}r=void 0}l=r;if(void 0===l){n.A(5);break}if(h.j){n.A(6);break}h.j=!0;return w(n,h.delete(),7);case 7:return n.return(e());case 6:throw new qi(l);case 5:return n.return(k);
case 2:p=ua(n);if(p instanceof DOMException?"VersionError"===p.name:"DOMError"in self&&p instanceof DOMError?"VersionError"===p.name:p instanceof Object&&"message"in p&&"An attempt was made to open a database using a lower version than the existing version."===p.message)return n.return(h.i(h.name,void 0,Object.assign(Object.assign({},d),{upgrade:void 0})));c();throw p;}})})};
this.h=b=e()}return this.h};var Xi=new Wi("YtIdbMeta",{Ca:{databases:!0},upgrade:function(a,b){1>b&&Gi(a,"databases",{keyPath:"actualName"})}});
function Yi(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,Xi.open(),2);d=e.i;return e.return(Ei(d,["databases"],{I:!0,mode:"readwrite"},function(f){var g=Fi(f,"databases");return g.get(a.actualName).then(function(h){if(h?a.actualName!==h.actualName||a.publicName!==h.publicName||a.userIdentifier!==h.userIdentifier||a.clearDataOnAuthChange!==h.clearDataOnAuthChange:1)return V(g.h.put(a,void 0)).then(function(){})})}))})})}
function Zi(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,Xi.open(),2);d=e.i;return e.return(d.delete("databases",a))})})}
function $i(){return H(this,function b(){var c,d;return x(b,function(e){if(1==e.h)return w(e,Xi.open(),2);if(3!=e.h)return c=e.i,w(e,c.count("databases"),3);d=e.i;return e.return(0<d)})})}
function aj(a){return H(this,function c(){var d,e;return x(c,function(f){return 1==f.h?(d=[],w(f,Xi.open(),2)):3!=f.h?(e=f.i,w(f,Ei(e,["databases"],{I:!0,mode:"readonly"},function(g){d.length=0;return Oi(Fi(g,"databases"),{},function(h){a(h.getValue())&&d.push(h.getValue());return h.continue()})}),3)):f.return(d)})})}
function bj(){return aj(function(a){return"LogsDatabaseV2"===a.publicName&&void 0!==a.userIdentifier})}
;var cj;
function dj(){return H(this,function b(){var c,d,e,f,g;return x(b,function(h){switch(h.h){case 1:if(Q("ytidb_is_supported_cache_success_result")&&(c=di(),null===c||void 0===c?0:c.hasSucceededOnce))return h.return(new ei(!0));var k;if(k=Cg)k=/WebKit\/([0-9]+)/.exec(Pb),k=!!(k&&600<=parseInt(k[1],10));k&&(k=/WebKit\/([0-9]+)/.exec(Pb),k=!(k&&602<=parseInt(k[1],10)));if(k)return h.return(gi(Error("YtIdb is not supported on iOS 8 or 9")));if(nc)return h.return(gi(Error("YtIdb is not supported on Edge")));try{if(d=
self,!(d.indexedDB&&d.IDBIndex&&d.IDBKeyRange&&d.IDBObjectStore))return h.return(gi(Error("Non-prefixed indexedDB APIs are missing")))}catch(l){return h.return(gi(l))}if(!("IDBTransaction"in self&&"objectStoreNames"in IDBTransaction.prototype))return h.return(gi(Error("IDBTransaction.prototype.objectStoreNames is missing")));ta(h,2);e={actualName:"yt-idb-test-do-not-use",publicName:"yt-idb-test-do-not-use",userIdentifier:void 0};return w(h,Yi(e),4);case 4:return w(h,Zi("yt-idb-test-do-not-use"),5);
case 5:return h.return(new ei(!0));case 2:f=ua(h);if(!fi()){h.A(6);break}ta(h,7);return w(h,$i(),9);case 9:return g=h.i,h.return(gi(f,g));case 7:return ua(h),h.return(gi(f));case 6:return h.return(gi(f))}})})}
function ej(){if(void 0!==cj)return cj;$h=!0;return cj=dj().then(function(a){$h=!1;a.log();return a.isSupported()})}
;function fj(){var a=new S("AUTH_INVALID");ai(a);throw a;throw Error("Datasync ID not set");}
function gj(a,b,c,d){var e;return H(this,function g(){var h,k;return x(g,function(l){switch(l.h){case 1:return w(l,hj({caller:"openDbImpl",publicName:a,version:b}),2);case 2:return ii(a),c?h={actualName:a,publicName:a,userIdentifier:void 0}:h=fj(),h.clearDataOnAuthChange=null!==(e=d.clearDataOnAuthChange)&&void 0!==e?e:!1,ta(l,3),w(l,Yi(h),5);case 5:return w(l,Ui(h.actualName,b,d),6);case 6:return l.return(l.i);case 3:return k=ua(l),ta(l,7),w(l,Zi(h.actualName),9);case 9:l.h=8;l.m=0;break;case 7:ua(l);
case 8:throw k;}})})}
function hj(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,ej(),2);if(!e.i)throw d=new S("IDB_NOT_SUPPORTED",{context:a}),ai(d),d;e.h=0})})}
function ij(a,b,c){c=void 0===c?{}:c;return gj(a,b,!1,c)}
function jj(a,b,c){c=void 0===c?{}:c;return gj(a,b,!0,c)}
function kj(a,b){b=void 0===b?{}:b;return H(this,function d(){var e;return x(d,function(f){if(1==f.h)return w(f,ej(),2);if(3!=f.h){if(!f.i)return f.return();ii(a);e=fj();return w(f,Vi(e.actualName,b),3)}return w(f,Zi(e.actualName),0)})})}
function lj(a,b){var c=this;a=a.map(function(d){return H(c,function f(){return x(f,function(g){return 1==g.h?w(g,Vi(d.actualName,b),2):w(g,Zi(d.actualName),0)})})});
return Promise.all(a).then(function(){})}
function mj(){var a=void 0===a?{}:a;return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,ej(),2);if(3!=e.h){if(!e.i)return e.return();ii("LogsDatabaseV2");return w(e,bj(),3)}d=e.i;return w(e,lj(d,a),0)})})}
function nj(a,b){b=void 0===b?{}:b;return H(this,function d(){return x(d,function(e){if(1==e.h)return w(e,ej(),2);if(3!=e.h){if(!e.i)return e.return();ii(a);return w(e,Vi(a,b),3)}return w(e,Zi(a),0)})})}
;function oj(a,b){Wi.call(this,a,b);this.options=b;ii(a)}
v(oj,Wi);oj.prototype.i=function(a,b,c){c=void 0===c?{}:c;return(this.options.Fa?jj:ij)(a,b,Object.assign(Object.assign({},c),{clearDataOnAuthChange:this.options.clearDataOnAuthChange}))};
oj.prototype.delete=function(a){a=void 0===a?{}:a;return(this.options.Fa?nj:kj)(this.name,a)};
function pj(a){var b;return function(){b||(b=new oj("LogsDatabaseV2",a));return b}}
;function qj(){T.call(this,function(){});
throw Error("Not allowed to instantiate the thennable outside of the core library.");}
v(qj,T);qj.reject=T.reject;qj.resolve=T.resolve;qj.all=T.all;var rj;function sj(){if(!rj){var a={};rj=pj({Ca:(a.LogsRequestsStore=!0,a.sapisid=!0,a.SWHealthLog=!0,a),Fa:!Q("nwl_use_ytidb_partitioning"),upgrade:function(b,c){2>c&&(Gi(b,"LogsRequestsStore",{keyPath:"id",autoIncrement:!0}).h.createIndex("newRequest",["status","authHash","interface","timestamp"],{unique:!1}),Gi(b,"sapisid"));3>c&&Gi(b,"SWHealthLog",{keyPath:"id",autoIncrement:!0}).h.createIndex("swHealthNewRequest",["interface","timestamp"],{unique:!1})},
version:3})}return rj().open()}
function tj(a){return H(this,function c(){var d,e,f,g,h;return x(c,function(k){switch(k.h){case 1:return d={startTime:R(),transactionType:"YT_IDB_TRANSACTION_TYPE_WRITE"},w(k,uj(),2);case 2:return e=k.i,w(k,sj(),3);case 3:return f=k.i,g=Object.assign(Object.assign({},a),{options:JSON.parse(JSON.stringify(a.options)),authHash:e,interface:F("INNERTUBE_CONTEXT_CLIENT_NAME",0)}),w(k,Ii(f,"LogsRequestsStore",g),4);case 4:return h=k.i,d.ob=R(),vj(d),k.return(h)}})})}
function wj(a){return H(this,function c(){var d,e,f,g,h,k,l,p;return x(c,function(n){switch(n.h){case 1:return d={startTime:R(),transactionType:"YT_IDB_TRANSACTION_TYPE_READ"},w(n,uj(),2);case 2:return e=n.i,f=F("INNERTUBE_CONTEXT_CLIENT_NAME",0),g=[a,e,f,0],h=[a,e,f,R()],k=IDBKeyRange.bound(g,h),w(n,sj(),3);case 3:return l=n.i,p=void 0,w(n,Ei(l,["LogsRequestsStore"],{mode:"readwrite",I:!0},function(r){return Ri(Fi(r,"LogsRequestsStore").index("newRequest"),{query:k,direction:"prev"},function(q){q.getValue()&&
(p=q.getValue(),"NEW"===a&&(p.status="QUEUED",q.update(p)))})}),4);
case 4:return d.ob=R(),vj(d),n.return(p)}})})}
function xj(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,sj(),2);d=e.i;return e.return(Ei(d,["LogsRequestsStore"],{mode:"readwrite",I:!0},function(f){var g=Fi(f,"LogsRequestsStore");return g.get(a).then(function(h){if(h)return h.status="QUEUED",V(g.h.put(h,void 0)).then(function(){return h})})}))})})}
function yj(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,sj(),2);d=e.i;return e.return(Ei(d,["LogsRequestsStore"],{mode:"readwrite",I:!0},function(f){var g=Fi(f,"LogsRequestsStore");return g.get(a).then(function(h){return h?(h.status="NEW",h.sendCount+=1,V(g.h.put(h,void 0)).then(function(){return h})):qj.resolve(void 0)})}))})})}
function zj(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,sj(),2);d=e.i;return e.return(d.delete("LogsRequestsStore",a))})})}
function Aj(){return H(this,function b(){var c;return x(b,function(d){if(1==d.h)return w(d,sj(),2);c=d.i;return d.return(c.clear("LogsRequestsStore"))})})}
function Bj(){return H(this,function b(){var c;return x(b,function(d){if(1==d.h)return w(d,sj(),2);c=d.i;return d.return(c.clear("SWHealthLog"))})})}
function Cj(){return H(this,function b(){var c,d;return x(b,function(e){return 1==e.h?w(e,sj(),2):3!=e.h?(c=e.i,d=R()-2592E6,w(e,Ei(c,["LogsRequestsStore"],{mode:"readwrite",I:!0},function(f){return Oi(Fi(f,"LogsRequestsStore"),{},function(g){if(g.getValue().timestamp<=d)return g.delete().then(function(){return g.continue()})})}),3)):Q("web_clean_sw_logs_store")?w(e,Ei(c,["SWHealthLog"],{mode:"readwrite",
I:!0},function(f){return Oi(Fi(f,"SWHealthLog"),{},function(g){if(g.getValue().timestamp<=d)return g.delete().then(function(){return g.continue()})})}),0):e.A(0)})})}
function Dj(){return H(this,function b(){return x(b,function(c){return 1==c.h?w(c,mj(),2):w(c,nj("LogsDatabaseV2"),0)})})}
function uj(){return H(this,function b(){var c;return x(b,function(d){if(1==d.h){Yh.h||(Yh.h=new Yh);var e={};var f=hd([]);f&&(e.Authorization=f,f=void 0,void 0===f&&(f=Number(F("SESSION_INDEX",0)),f=isNaN(f)?0:f),e["X-Goog-AuthUser"]=f,"INNERTUBE_HOST_OVERRIDE"in of||(e["X-Origin"]=window.location.origin),Q("pageid_as_header_web")&&"DELEGATED_SESSION_ID"in of&&(e["X-Goog-PageId"]=F("DELEGATED_SESSION_ID")));e instanceof Ee||(f=new Ee(Ka),Fe(f,2,e),e=f);return w(d,e,2)}c=d.i;e=d.return;f=Eh(c);var g=
new zd;g.update(JSON.stringify(f,Object.keys(f).sort()));f=g.digest();g="";for(var h=0;h<f.length;h++)g+="0123456789ABCDEF".charAt(Math.floor(f[h]/16))+"0123456789ABCDEF".charAt(f[h]%16);return e.call(d,g)})})}
function Ej(a){return H(this,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,sj(),2);d=e.i;return w(e,Ii(d,"sapisid",a,"sapisid"),0)})})}
function Fj(){return H(this,function b(){var c,d;return x(b,function(e){if(1==e.h)return w(e,sj(),2);if(3!=e.h)return c=e.i,w(e,c.get("sapisid","sapisid"),3);d=e.i;return e.return(d||"")})})}
function vj(a){var b=xf("nwl_latency_sampling_rate",.01);.02<b||Math.random()<=b&&Rh("nwl_transaction_latency_payload",a)}
;var Gj=["__Secure-1PAPISID","SAPISID","__Secure-3PAPISID"];function Hj(){for(var a=u(Gj),b=a.next();!b.done;b=a.next())if(b=ed.get(b.value))return b;return"LOGGED_OUT"}
function Ij(){ue.call(this);this.pollingInterval=3E3;this.i=[null,null,null];this.m=!1;Jj(this)}
v(Ij,ue);function Kj(){Ij.h||(Ij.h=new Ij);var a=Ij.h;a.m=!0;a.verifyUser();Lj(a)}
Ij.prototype.verifyUser=function(){var a=Jj(this),b=a.Xa;if(!a.mb)return Lj(this),!0;ve(this,"ytsessionchange");b&&ve(this,"ytuserinvalid");Lj(this);return!1};
function Jj(a){var b=Gj.map(function(e){var f;return null!==(f=ed.get(e))&&void 0!==f?f:""}),c=b.some(function(e,f){return a.i&&""!==a.i[f]&&""===e}),d=b.some(function(e,f){return a.i&&a.i[f]!==e});
a.i=b;return{Xa:c,mb:d}}
function Lj(a){a.m&&(Mj(a),a.l=Nf(function(){a.verifyUser()},a.pollingInterval))}
function Mj(a){a.l&&(Sf(a.l),a.l=void 0)}
;var Nj;function Oj(){Nj||(Nj=new Fh("yt.offline"));return Nj}
function Pj(a){if(Q("offline_error_handling")){var b=Oj().get("errors",!0)||{};b[a.message]={name:a.name,stack:a.stack};a.level&&(b[a.message].level=a.level);Oj().set("errors",b,2592E3,!0)}}
function Qj(){if(Q("offline_error_handling")){var a=Oj().get("errors",!0);if(a){for(var b in a)if(a[b]){var c=new hi(b,"sent via offline_errors");c.name=a[b].name;c.stack=a[b].stack;c.level=a[b].level;sf(c)}Oj().set("errors",{},2592E3,!0)}}}
;var Rj=xf("network_polling_interval",3E4);function Sj(){ue.call(this);this.K=0;this.o=this.l=!1;this.B=0;this.m=this.J=!1;this.i=Tj();this.m=Q("validate_network_status");Uj(this);Vj(this)}
v(Sj,ue);function Wj(a,b){a.l=!0;if(void 0===b?0:b)a.K||Xj(a)}
function Tj(){var a=window.navigator.onLine;return void 0===a?!0:a}
function Vj(a){window.addEventListener("online",function(){return H(a,function c(){var d=this;return x(c,function(e){if(1==e.h)return d.m?w(e,Yj(d),2):(d.i=!0,d.l&&ve(d,"ytnetworkstatus-online"),e.A(2));Zj(d);d.J&&Qj();e.h=0})})})}
function Uj(a){window.addEventListener("offline",function(){return H(a,function c(){var d=this;return x(c,function(e){if(1==e.h)return d.m?w(e,Yj(d),2):(d.i=!1,d.l&&ve(d,"ytnetworkstatus-offline"),e.A(2));Zj(d);e.h=0})})})}
function Xj(a){a.K=Nf(function(){return H(a,function c(){var d=this;return x(c,function(e){if(1==e.h){if(Q("trigger_nsm_validation_checks_with_nwl")&&!d.i)return w(e,Yj(d),3);if(Tj()){if(!1!==d.i)return e.A(3);d.o=!0;d.B=R();return d.l?d.m?w(e,Yj(d),11):(d.i=!0,ve(d,"ytnetworkstatus-online"),e.A(11)):e.A(11)}if(!0!==d.i)return e.A(3);d.o=!0;d.B=R();return d.l?d.m?w(e,Yj(d),3):(d.i=!1,ve(d,"ytnetworkstatus-offline"),e.A(3)):e.A(3)}if(3!=e.h)return d.J&&Qj(),e.A(3);Xj(d);e.h=0})})},Rj)}
function Zj(a){a.o&&(tf(new hi("NetworkStatusManager state did not match poll",R()-a.B)),a.o=!1)}
function Yj(a,b){return a.C?a.C:a.C=new Promise(function(c){return H(a,function e(){var f,g,h,k=this;return x(e,function(l){switch(l.h){case 1:return f=new AbortController,g=f.signal,h=!1,ta(l,2,3),k.L=Pf(function(){f.abort()},b||2E4),w(l,fetch("/generate_204",{method:"HEAD",
signal:g}),5);case 5:h=!0;case 3:va(l);k.C=void 0;Sf(k.L);h!==k.i&&(k.i=h,k.i&&k.l?ve(k,"ytnetworkstatus-online"):k.l&&ve(k,"ytnetworkstatus-offline"));c(h);wa(l);break;case 2:ua(l),h=!1,l.A(3)}})})})}
;function ak(a){a=void 0===a?{}:a;ue.call(this);var b=this;this.l=this.o=0;Sj.h||(Sj.h=new Sj);this.i=Sj.h;Wj(this.i,a.La);a.Wa&&(this.i.J=!0);a.ga?(this.ga=a.ga,le(this.i,"ytnetworkstatus-online",function(){bk(b,"publicytnetworkstatus-online")}),le(this.i,"ytnetworkstatus-offline",function(){bk(b,"publicytnetworkstatus-offline")})):(le(this.i,"ytnetworkstatus-online",function(){ve(b,"publicytnetworkstatus-online")}),le(this.i,"ytnetworkstatus-offline",function(){ve(b,"publicytnetworkstatus-offline")}))}
v(ak,ue);function ck(){var a=dk().i;a.m||a.i===Tj()||tf(new hi("NetworkStatusManager isOnline does not match window status"));return a.i}
function ek(){var a=dk();return H(a,function c(){var d=this;return x(c,function(e){return e.return(Yj(d.i,void 0))})})}
function bk(a,b){a.ga?a.l?(Sf(a.o),a.o=Pf(function(){a.m!==b&&(ve(a,b),a.m=b,a.l=R())},a.ga-(R()-a.l))):(ve(a,b),a.m=b,a.l=R()):ve(a,b)}
;var fk=!1,gk=!1,hk=0,ik=0,jk;function kk(){H(this,function b(){var c,d,e,f;return x(b,function(g){switch(g.h){case 1:return w(g,ej(),2);case 2:(c=g.i)&&(gk=!0);d=Q("networkless_logging");if(c&&d)return Q("nwl_use_ytidb_partitioning")?w(g,nj("LogsDatabaseV2"),8):w(g,mj(),8);if(!c){g.A(0);break}return w(g,Dj(),0);case 8:return Kj(),document.addEventListener("ytsessionchange",function(){lk()}),w(g,Fj(),11);
case 11:e=g.i;f=Hj();if(e===f){g.A(12);break}lk();return w(g,Ej(f),12);case 12:if(!(Q("enable_nwl_cleaning_logic")&&Math.random()<=xf("nwl_cleaning_rate",.1))){g.A(14);break}return w(g,Cj(),14);case 14:fk=!0;mk();ck()&&nk();le(dk(),"publicytnetworkstatus-online",nk);le(dk(),"publicytnetworkstatus-offline",ok);if(!Q("networkless_immediately_drop_sw_health_store")){g.A(16);break}return w(g,pk(),16);case 16:if(Q("networkless_immediately_drop_all_requests"))return w(g,Dj(),0);g.A(0)}})})}
function qk(a,b){function c(d){var e=ck();if(!fk||!d||e&&Q("vss_networkless_bypass_write"))ug(a,b);else{var f={url:a,options:b,timestamp:R(),status:"NEW",sendCount:0};tj(f).then(function(g){f.id=g;(ck()||Q("networkless_always_online"))&&rk(f)}).catch(function(g){rk(f);
ck()?sf(g):Pj(g)})}}
b=void 0===b?{}:b;Q("skip_is_supported_killswitch")?ej().then(function(d){c(d)}):c(gk)}
function sk(a,b){function c(d){if(fk&&d){var e={url:a,options:b,timestamp:R(),status:"NEW",sendCount:0},f=!1,g=b.onSuccess?b.onSuccess:function(){};
e.options.onSuccess=function(h,k){void 0!==e.id?zj(e.id):f=!0;g(h,k)};
ug(e.url,e.options);tj(e).then(function(h){e.id=h;f&&zj(e.id)}).catch(function(h){ck()?sf(h):Pj(h)})}else ug(a,b)}
b=void 0===b?{}:b;Q("skip_is_supported_killswitch")?ej().then(function(d){c(d)}):c(gk)}
function nk(){var a=this;hk||(hk=Pf(function(){return H(a,function c(){var d;return x(c,function(e){if(1==e.h)return w(e,wj("NEW"),2);if(3!=e.h)return d=e.i,d?w(e,rk(d),3):(ok(),e.return());hk=0;nk();e.h=0})})},100))}
function ok(){Sf(hk);hk=0}
function rk(a){return H(this,function c(){var d;return x(c,function(e){switch(e.h){case 1:if(void 0===a.id){e.A(2);break}return w(e,xj(a.id),3);case 3:(d=e.i)?a=d:tf(Error("The request cannot be found in the database."));case 2:if(tk(a,2592E6)){e.A(4);break}tf(Error("Networkless Logging: Stored logs request expired age limit"));if(void 0===a.id){e.A(5);break}return w(e,zj(a.id),5);case 5:return e.return();case 4:var f=a=uk(a),g,h;if(null===(h=null===(g=null===f||void 0===f?void 0:f.options)||void 0===
g?void 0:g.postParams)||void 0===h?0:h.requestTimeMs)f.options.postParams.requestTimeMs=Math.round(R());(a=f)&&ug(a.url,a.options);e.h=0}})})}
function uk(a){var b=this,c=a.options.onError?a.options.onError:function(){};
a.options.onError=function(e,f){return H(b,function h(){return x(h,function(k){switch(k.h){case 1:if(!(Q("trigger_nsm_validation_checks_with_nwl")&&ik<=xf("potential_esf_error_limit",10))){k.A(2);break}return w(k,ek(),3);case 3:if(ck())ik++;else return c(e,f),k.return();case 2:if(void 0===(null===a||void 0===a?void 0:a.id)){k.A(4);break}return 1>a.sendCount?w(k,yj(a.id),8):w(k,zj(a.id),4);case 8:Pf(function(){ck()&&nk()},5E3);
case 4:c(e,f),k.h=0}})})};
var d=a.options.onSuccess?a.options.onSuccess:function(){};
a.options.onSuccess=function(e,f){return H(b,function h(){return x(h,function(k){if(1==k.h)return void 0===(null===a||void 0===a?void 0:a.id)?k.A(2):w(k,zj(a.id),2);d(e,f);k.h=0})})};
return a}
function tk(a,b){a=a.timestamp;return R()-a>=b?!1:!0}
function mk(){var a=this;wj("QUEUED").then(function(b){b&&!tk(b,12E4)&&Pf(function(){return H(a,function d(){return x(d,function(e){if(1==e.h)return void 0===b.id?e.A(2):w(e,yj(b.id),2);mk();e.h=0})})})})}
function lk(){Aj().catch(function(a){sf(a)})}
function pk(){return H(this,function b(){return x(b,function(c){return c.return(Bj().catch(function(d){sf(d)}))})})}
function dk(){jk||(jk=new ak({Wa:!0,La:Q("trigger_nsm_validation_checks_with_nwl")}));return jk}
;function vk(a){var b=this;this.h=null;a?this.h=a:Ch()&&(this.h=mh());Nf(function(){Kh(b)},5E3)}
vk.prototype.isReady=function(){!this.h&&Ch()&&(this.h=mh());return!!this.h};
function ph(a,b,c,d){function e(r){r=void 0===r?!1:r;var q;if(d.retry&&"www.youtube-nocookie.com"!=h&&(r||(q=Ih(b,c,l,k)),q)){var D=g.onSuccess,I=g.onFetchSuccess;g.onSuccess=function(J,ba){Jh(q);D(J,ba)};
c.onFetchSuccess=function(J,ba){Jh(q);I(J,ba)}}try{r&&d.retry&&!d.Ba.bypassNetworkless?(g.method="POST",!d.Ba.writeThenSend&&Q("nwl_send_fast_on_unload")?sk(n,g):qk(n,g)):(g.method="POST",g.postParams||(g.postParams={}),ug(n,g))}catch(J){if("InvalidAccessError"==J.name)q&&(Jh(q),q=0),tf(Error("An extension is blocking network request."));
else throw J;}q&&Nf(function(){Kh(a)},5E3)}
!F("VISITOR_DATA")&&"visitor_id"!==b&&.01>Math.random()&&tf(new hi("Missing VISITOR_DATA when sending innertube request.",b,c,d));if(!a.isReady()){var f=new hi("innertube xhrclient not ready",b,c,d);sf(f);throw f;}var g={headers:{"Content-Type":"application/json"},method:"POST",postParams:c,postBodyFormat:"JSON",onTimeout:function(){d.onTimeout()},
onFetchTimeout:d.onTimeout,onSuccess:function(r,q){if(d.onSuccess)d.onSuccess(q)},
onFetchSuccess:function(r){if(d.onSuccess)d.onSuccess(r)},
onError:function(r,q){if(d.onError)d.onError(q)},
onFetchError:function(r){if(d.onError)d.onError(r)},
timeout:d.timeout,withCredentials:!0},h="";(f=a.h.Ta)&&(h=f);var k=a.h.Va||!1,l=Dh(k,h,d);Object.assign(g.headers,l);g.headers.Authorization&&!h&&(g.headers["x-origin"]=window.location.origin);f="/youtubei/"+a.h.innertubeApiVersion+"/"+b;var p={alt:"json"};a.h.Ua&&g.headers.Authorization||(p.key=a.h.innertubeApiKey);var n=ig(""+h+f,p||{},!0);fk?ej().then(function(r){e(r)}):e(!1)}
;function wk(a,b,c){c=void 0===c?{}:c;var d=vk;F("ytLoggingEventsDefaultDisabled",!1)&&vk==vk&&(d=null);rh(a,b,d,c)}
;var xk=[{za:function(a){return"Cannot read property '"+a.key+"'"},
qa:{TypeError:[{regexp:/Cannot read property '([^']+)' of (null|undefined)/,groups:["key","value"]},{regexp:/\u65e0\u6cd5\u83b7\u53d6\u672a\u5b9a\u4e49\u6216 (null|undefined) \u5f15\u7528\u7684\u5c5e\u6027\u201c([^\u201d]+)\u201d/,groups:["value","key"]},{regexp:/\uc815\uc758\ub418\uc9c0 \uc54a\uc74c \ub610\ub294 (null|undefined) \ucc38\uc870\uc778 '([^']+)' \uc18d\uc131\uc744 \uac00\uc838\uc62c \uc218 \uc5c6\uc2b5\ub2c8\ub2e4./,groups:["value","key"]},{regexp:/No se puede obtener la propiedad '([^']+)' de referencia nula o sin definir/,
groups:["key"]},{regexp:/Unable to get property '([^']+)' of (undefined or null) reference/,groups:["key","value"]}],Error:[{regexp:/(Permission denied) to access property "([^']+)"/,groups:["reason","key"]}]}},{za:function(a){return"Cannot call '"+a.key+"'"},
qa:{TypeError:[{regexp:/(?:([^ ]+)?\.)?([^ ]+) is not a function/,groups:["base","key"]},{regexp:/([^ ]+) called on (null or undefined)/,groups:["key","value"]},{regexp:/Object (.*) has no method '([^ ]+)'/,groups:["base","key"]},{regexp:/Object doesn't support property or method '([^ ]+)'/,groups:["key"]},{regexp:/\u30aa\u30d6\u30b8\u30a7\u30af\u30c8\u306f '([^']+)' \u30d7\u30ed\u30d1\u30c6\u30a3\u307e\u305f\u306f\u30e1\u30bd\u30c3\u30c9\u3092\u30b5\u30dd\u30fc\u30c8\u3057\u3066\u3044\u307e\u305b\u3093/,
groups:["key"]},{regexp:/\uac1c\uccb4\uac00 '([^']+)' \uc18d\uc131\uc774\ub098 \uba54\uc11c\ub4dc\ub97c \uc9c0\uc6d0\ud558\uc9c0 \uc54a\uc2b5\ub2c8\ub2e4./,groups:["key"]}]}}];function yk(){this.h=[];this.i=[]}
var zk;function Ak(){zk||(zk=new yk);return zk}
;var Bk=new M;function Ck(a){function b(){return a.charCodeAt(d++)}
var c=a.length,d=0;do{var e=Dk(b);if(Infinity===e)break;var f=e>>3;switch(e&7){case 0:e=Dk(b);if(2===f)return e;break;case 1:if(2===f)return;d+=8;break;case 2:e=Dk(b);if(2===f)return a.substr(d,e);d+=e;break;case 5:if(2===f)return;d+=4;break;default:return}}while(d<c)}
function Dk(a){var b=a(),c=b&127;if(128>b)return c;b=a();c|=(b&127)<<7;if(128>b)return c;b=a();c|=(b&127)<<14;if(128>b)return c;b=a();return 128>b?c|(b&127)<<21:Infinity}
;function Ek(a,b,c,d){if(a)if(Array.isArray(a)){var e=d;for(d=0;d<a.length&&!(a[d]&&(e+=Fk(d,a[d],b,c),500<e));d++);d=e}else if("object"===typeof a)for(e in a){if(a[e]){var f=e;var g=a[e],h=b,k=c;f="string"!==typeof g||"clickTrackingParams"!==f&&"trackingParams"!==f?0:(g=Ck(atob(g.replace(/-/g,"+").replace(/_/g,"/"))))?Fk(f+".ve",g,h,k):0;d+=f;d+=Fk(e,a[e],b,c);if(500<d)break}}else c[b]=Gk(a),d+=c[b].length;else c[b]=Gk(a),d+=c[b].length;return d}
function Fk(a,b,c,d){c+="."+a;a=Gk(b);d[c]=a;return c.length+a.length}
function Gk(a){return("string"===typeof a?a:String(JSON.stringify(a))).substr(0,500)}
;var Hk=new Set,Ik=0,Jk=0,Kk=0,Lk=[],Mk=["PhantomJS","Googlebot","TO STOP THIS SECURITY SCAN go/scan"];function Nk(a){Ok(a,"WARNING")}
function Ok(a,b,c,d,e,f){f=void 0===f?{}:f;f.name=c||F("INNERTUBE_CONTEXT_CLIENT_NAME",1);f.version=d||F("INNERTUBE_CONTEXT_CLIENT_VERSION",void 0);c=f||{};b=void 0===b?"ERROR":b;b=void 0===b?"ERROR":b;if(a&&(a.hasOwnProperty("level")&&a.level&&(b=a.level),Q("console_log_js_exceptions")&&(d=[],d.push("Name: "+a.name),d.push("Message: "+a.message),a.hasOwnProperty("params")&&d.push("Error Params: "+JSON.stringify(a.params)),a.hasOwnProperty("args")&&d.push("Error args: "+JSON.stringify(a.args)),d.push("File name: "+
a.fileName),d.push("Stacktrace: "+a.stack),window.console.log(d.join("\n"),a)),!(5<=Ik))){var g=Bd(a);d=g.message||"Unknown Error";e=g.name||"UnknownError";var h=g.stack||a.i||"Not available";h.startsWith(e+": "+d)&&(f=h.split("\n"),f.shift(),h=f.join("\n"));f=g.lineNumber||"Not available";g=g.fileName||"Not available";var k=0;if(a.hasOwnProperty("args")&&a.args&&a.args.length)for(var l=0;l<a.args.length&&!(k=Ek(a.args[l],"params."+l,c,k),500<=k);l++);else if(a.hasOwnProperty("params")&&a.params){var p=
a.params;if("object"===typeof a.params)for(l in p){if(p[l]){var n="params."+l,r=Gk(p[l]);c[n]=r;k+=n.length+r.length;if(500<k)break}}else c.params=Gk(p)}if(Lk.length)for(l=0;l<Lk.length&&!(k=Ek(Lk[l],"params.context."+l,c,k),500<=k);l++);navigator.vendor&&!c.hasOwnProperty("vendor")&&(c["device.vendor"]=navigator.vendor);l={message:d,name:e,lineNumber:f,fileName:g,stack:h,params:c,sampleWeight:1};c=Number(a.columnNumber);isNaN(c)||(l.lineNumber=l.lineNumber+":"+c);if("IGNORED"===a.level)a=0;else a:{a=
Ak();c=u(a.i);for(d=c.next();!d.done;d=c.next())if(d=d.value,l.message&&l.message.match(d.Kk)){a=d.weight;break a}a=u(a.h);for(c=a.next();!c.done;c=a.next())if(c=c.value,c.Ia(l)){a=c.weight;break a}a=1}l.sampleWeight=a;a=u(xk);for(c=a.next();!c.done;c=a.next())if(c=c.value,c.qa[l.name])for(e=u(c.qa[l.name]),d=e.next();!d.done;d=e.next())if(f=d.value,d=l.message.match(f.regexp)){l.params["params.error.original"]=d[0];e=f.groups;f={};for(g=0;g<e.length;g++)f[e[g]]=d[g+1],l.params["params.error."+e[g]]=
d[g+1];l.message=c.za(f);break}l.params||(l.params={});a=Ak();l.params["params.errorServiceSignature"]="msg="+a.i.length+"&cb="+a.h.length;l.params["params.serviceWorker"]="false";y.document&&y.document.querySelectorAll&&(l.params["params.fscripts"]=String(document.querySelectorAll("script:not([nonce])").length));window.yterr&&"function"===typeof window.yterr&&window.yterr(l);if(0!==l.sampleWeight&&!Hk.has(l.message)){"ERROR"===b?(Bk.S("handleError",l),Q("record_app_crashed_web")&&0===Kk&&1===l.sampleWeight&&
(Kk++,wk("appCrashed",{appCrashType:"APP_CRASH_TYPE_BREAKPAD"})),Jk++):"WARNING"===b&&Bk.S("handleWarning",l);if(Q("kevlar_gel_error_routing")){a=b;b:{c=u(Mk);for(d=c.next();!d.done;d=c.next())if(Dg(d.value.toLowerCase())){c=!0;break b}c=!1}if(c)c=void 0;else{d={stackTrace:l.stack};l.fileName&&(d.filename=l.fileName);c=l.lineNumber&&l.lineNumber.split?l.lineNumber.split(":"):[];0!==c.length&&(1!==c.length||isNaN(Number(c[0]))?2!==c.length||isNaN(Number(c[0]))||isNaN(Number(c[1]))||(d.lineNumber=Number(c[0]),
d.columnNumber=Number(c[1])):d.lineNumber=Number(c[0]));c={level:"ERROR_LEVEL_UNKNOWN",message:l.message,errorClassName:l.name,sampleWeight:l.sampleWeight};"ERROR"===a?c.level="ERROR_LEVEL_ERROR":"WARNING"===a&&(c.level="ERROR_LEVEL_WARNNING");d={isObfuscated:!0,browserStackInfo:d};e={pageUrl:window.location.href,kvPairs:[]};F("FEXP_EXPERIMENTS")&&(e.experimentIds=F("FEXP_EXPERIMENTS"));if(f=l.params)for(g=u(Object.keys(f)),h=g.next();!h.done;h=g.next())h=h.value,e.kvPairs.push({key:"client."+h,value:String(f[h])});
f=F("SERVER_NAME",void 0);g=F("SERVER_VERSION",void 0);f&&g&&(e.kvPairs.push({key:"server.name",value:f}),e.kvPairs.push({key:"server.version",value:g}));c={errorMetadata:e,stackTrace:d,logMessage:c}}c&&(wk("clientError",c),("ERROR"===a||Q("errors_flush_gel_always_killswitch"))&&hh())}if(!Q("suppress_error_204_logging")){a=l.params||{};b={urlParams:{a:"logerror",t:"jserror",type:l.name,msg:l.message.substr(0,250),line:l.lineNumber,level:b,"client.name":a.name},postParams:{url:F("PAGE_NAME",window.location.href),
file:l.fileName},method:"POST"};a.version&&(b["client.version"]=a.version);if(b.postParams){l.stack&&(b.postParams.stack=l.stack);c=u(Object.keys(a));for(d=c.next();!d.done;d=c.next())d=d.value,b.postParams["client."+d]=a[d];if(a=F("LATEST_ECATCHER_SERVICE_TRACKING_PARAMS",void 0))for(c=u(Object.keys(a)),d=c.next();!d.done;d=c.next())d=d.value,b.postParams[d]=a[d];a=F("SERVER_NAME",void 0);c=F("SERVER_VERSION",void 0);a&&c&&(b.postParams["server.name"]=a,b.postParams["server.version"]=c)}ug(F("ECATCHER_REPORT_HOST",
"")+"/error_204",b)}Hk.add(l.message);Ik++}}}
function Pk(a,b){for(var c=[],d=1;d<arguments.length;++d)c[d-1]=arguments[d];a.args||(a.args=[]);a.args.push.apply(a.args,c instanceof Array?c:ha(u(c)))}
;var Qk={Vb:29434,Yb:3611,Oe:3854,ig:42993,Qi:4724,Bj:96370,pb:27686,qb:85013,rb:23462,tb:42016,ub:62407,vb:26926,sb:43781,wb:51236,xb:79148,yb:50160,zb:77504,Lb:87907,Mb:18630,Nb:54445,Ob:80935,Pb:105675,Qb:37521,Rb:47786,Sb:98349,Tb:123695,Ub:6827,Wb:7282,Xb:124448,cc:32276,ac:76278,dc:93911,ec:106531,fc:27259,hc:27262,ic:27263,kc:21759,lc:27107,mc:62936,nc:49568,oc:38408,pc:80637,qc:68727,sc:68728,tc:80353,uc:80356,wc:74610,xc:45707,yc:83962,zc:83970,Ac:46713,Bc:89711,Cc:74612,Dc:93265,Ec:74611,
Gc:113533,Hc:93252,Ic:99357,Kc:94521,Lc:114252,Mc:113532,Nc:94522,Jc:94583,Oc:88E3,Pc:93253,Qc:93254,Rc:94387,Sc:94388,Tc:93255,Uc:97424,Fc:72502,Vc:110111,Wc:76019,Yc:117092,Zc:117093,Xc:89431,bd:110466,cd:77240,dd:60508,ed:105350,fd:73393,gd:113534,hd:92098,jd:84517,kd:83759,ld:80357,md:86113,nd:72598,od:72733,pd:107349,qd:124275,rd:118203,sd:117431,td:117429,ud:117430,vd:117432,wd:120080,xd:117259,yd:121692,zd:97615,Ad:31402,Bd:84774,Cd:95117,Dd:98930,Ed:98931,Fd:98932,Gd:43347,Hd:45474,Id:100352,
Jd:84758,Kd:98443,Ld:117985,Md:74613,Nd:74614,Od:64502,Pd:74615,Qd:74616,Rd:122224,Sd:74617,Td:77820,Ud:74618,Vd:93278,Wd:93274,Xd:93275,Yd:93276,Zd:22110,ae:29433,ce:120541,ee:82047,ge:113550,he:75836,ie:75837,je:42352,ke:84512,le:76065,me:75989,ne:16623,oe:32594,pe:27240,qe:32633,re:74858,te:3945,se:16989,ue:45520,we:25488,xe:25492,ye:25494,ze:55760,Ae:14057,Be:18451,Ce:57204,De:57203,Ee:17897,Fe:57205,Ge:18198,He:17898,Ie:17909,Je:43980,Ke:46220,Le:11721,Me:49954,Ne:96369,Pe:56251,Qe:25624,Re:16906,
Se:99999,Te:68172,Ue:27068,Ve:47973,We:72773,Xe:26970,Ye:26971,Ze:96805,af:17752,bf:73233,cf:109512,df:22256,ef:14115,ff:22696,gf:89278,hf:89277,jf:109513,kf:43278,lf:43459,mf:43464,nf:89279,pf:43717,qf:55764,rf:22255,sf:89281,tf:40963,uf:43277,vf:43442,wf:91824,xf:120137,yf:96367,zf:36850,Af:72694,Bf:37414,Cf:36851,Ef:124863,Df:121343,Ff:73491,Gf:54473,Hf:43375,If:46674,Jf:32473,Kf:72901,Lf:72906,Mf:50947,Nf:50612,Of:50613,Pf:50942,Qf:84938,Rf:84943,Sf:84939,Tf:84941,Uf:84944,Vf:84940,Wf:84942,Xf:35585,
Yf:51926,Zf:79983,ag:63238,cg:18921,dg:63241,eg:57893,fg:41182,gg:33424,hg:22207,jg:36229,kg:22206,lg:22205,mg:18993,ng:19001,og:18990,pg:18991,qg:18997,rg:18725,sg:19003,tg:36874,ug:44763,vg:33427,wg:67793,xg:22182,yg:37091,zg:34650,Ag:50617,Bg:47261,Cg:22287,Dg:25144,Eg:97917,Fg:62397,Gg:36961,Hg:108035,Ig:27426,Jg:27857,Kg:27846,Lg:27854,Mg:69692,Ng:61411,Og:39299,Pg:38696,Qg:62520,Rg:36382,Sg:108701,Tg:50663,Ug:36387,Vg:14908,Wg:37533,Xg:105443,Yg:61635,Zg:62274,ah:65702,bh:65703,dh:65701,eh:76256,
fh:37671,gh:49953,ih:36216,jh:28237,kh:39553,lh:29222,mh:26107,nh:38050,oh:26108,qh:120745,ph:26109,rh:26110,sh:66881,th:28236,uh:14586,vh:57929,wh:74723,xh:44098,yh:44099,zh:23528,Ah:61699,Bh:59149,Ch:101951,Dh:97346,Eh:118051,Fh:95102,Gh:64882,Hh:119505,Ih:63595,Jh:63349,Kh:95101,Lh:75240,Mh:27039,Nh:68823,Oh:21537,Ph:83464,Qh:75707,Rh:83113,Sh:101952,Th:101953,Vh:79610,Wh:24402,Xh:24400,Yh:32925,Zh:57173,ai:122502,bi:64423,ci:64424,di:33986,fi:100828,gi:21409,hi:11070,ii:11074,ji:17880,ki:14001,
mi:30709,ni:30707,oi:30711,ri:30710,si:30708,li:26984,ti:63648,vi:63649,wi:51879,xi:111059,yi:5754,zi:20445,Ai:110386,Bi:113746,Ci:66557,Di:17310,Ei:28631,Fi:21589,Gi:68012,Hi:60480,Ii:31571,Ji:76980,Ki:41577,Li:45469,Mi:38669,Ni:13768,Oi:13777,Pi:62985,Ri:59369,Si:43927,Ti:43928,Ui:12924,Vi:100355,Yi:56219,Zi:27669,aj:10337,Xi:47896,bj:122629,cj:121258,dj:107598,ej:96639,fj:107536,gj:96661,hj:96658,ij:116646,jj:121122,kj:96660,lj:104443,mj:96659,nj:106442,oj:63667,pj:63668,qj:63669,rj:78314,sj:55761,
tj:96368,uj:67374,vj:48992,wj:49956,xj:31961,yj:26388,zj:23811,Aj:5E4,Cj:47355,Dj:47356,Ej:37935,Fj:45521,Gj:21760,Hj:83769,Ij:49977,Jj:49974,Kj:93497,Lj:93498,Mj:34325,Nj:115803,Oj:123707,Pj:100081,Qj:35309,Rj:68314,Sj:25602,Tj:100339,Uj:59018,Vj:18248,Wj:50625,Xj:9729,Yj:37168,Zj:37169,ak:21667,bk:16749,ck:18635,dk:39305,ek:18046,fk:53969,gk:8213,hk:93926,ik:102852,jk:110099,kk:22678,lk:69076,nk:100856,pk:17736,qk:3832,rk:55759,sk:64031,tk:93044,uk:93045,vk:34388,wk:17657,xk:17655,yk:39579,zk:39578,
Ak:77448,Bk:8196,Ck:11357,Dk:69877,Ek:8197,Fk:82039};function Rk(a,b,c){L.call(this);var d=this;c=c||F("POST_MESSAGE_ORIGIN",void 0)||window.document.location.protocol+"//"+window.document.location.hostname;this.j=b||null;this.C="*";this.l=c;this.sessionId=null;this.channel="widget";this.F=!!a;this.B=function(e){a:if(!("*"!=d.l&&e.origin!=d.l||d.j&&e.source!=d.j||"string"!==typeof e.data)){try{var f=JSON.parse(e.data)}catch(g){break a}if(!(null==f||d.F&&(d.sessionId&&d.sessionId!=f.id||d.channel&&d.channel!=f.channel))&&f)switch(f.event){case "listening":"null"!=
e.origin&&(d.l=d.C=e.origin);d.j=e.source;d.sessionId=f.id;d.i&&(d.i(),d.i=null);break;case "command":d.m&&(!d.o||0<=$a(d.o,f.func))&&d.m(f.func,f.args,e.origin)}}};
this.o=this.i=this.m=null;window.addEventListener("message",this.B)}
v(Rk,L);Rk.prototype.sendMessage=function(a,b){if(b=b||this.j){this.sessionId&&(a.id=this.sessionId);this.channel&&(a.channel=this.channel);try{var c=JSON.stringify(a);b.postMessage(c,this.C)}catch(d){tf(d)}}};
Rk.prototype.D=function(){window.removeEventListener("message",this.B);L.prototype.D.call(this)};function Sk(){this.l=[];this.isReady=!1;this.u={};var a=this.i=new Rk(!!F("WIDGET_ID_ENFORCE")),b=this.cb.bind(this);a.m=b;a.o=null;this.i.channel="widget";if(a=F("WIDGET_ID"))this.i.sessionId=a}
m=Sk.prototype;m.cb=function(a,b,c){"addEventListener"===a&&b?(a=b[0],this.u[a]||"onReady"===a||(this.addEventListener(a,Tk(this,a)),this.u[a]=!0)):this.ra(a,b,c)};
m.ra=function(){};
function Tk(a,b){return function(c){return a.sendMessage(b,c)}}
m.addEventListener=function(){};
m.Na=function(){this.isReady=!0;this.sendMessage("initialDelivery",this.la());this.sendMessage("onReady");E(this.l,this.Ea,this);this.l=[]};
m.la=function(){return null};
function Uk(a,b){a.sendMessage("infoDelivery",b)}
m.Ea=function(a){this.isReady?this.i.sendMessage(a):this.l.push(a)};
m.sendMessage=function(a,b){this.Ea({event:a,info:void 0===b?null:b})};
m.dispose=function(){this.i=null};function Vk(a){return(0===a.search("cue")||0===a.search("load"))&&"loadModule"!==a}
function Wk(a,b,c){"string"===typeof a&&(a={mediaContentUrl:a,startSeconds:b,suggestedQuality:c});a:{if((b=a.mediaContentUrl)&&(b=/\/([ve]|embed)\/([^#?]+)/.exec(b))&&b[2]){b=b[2];break a}b=null}a.videoId=b;return Xk(a)}
function Xk(a,b,c){if("string"===typeof a)return{videoId:a,startSeconds:b,suggestedQuality:c};b=["endSeconds","startSeconds","mediaContentUrl","suggestedQuality","videoId"];c={};for(var d=0;d<b.length;d++){var e=b[d];a[e]&&(c[e]=a[e])}return c}
function Yk(a,b,c,d){if(Oa(a)&&!Array.isArray(a)){b="playlist list listType index startSeconds suggestedQuality".split(" ");c={};for(d=0;d<b.length;d++){var e=b[d];a[e]&&(c[e]=a[e])}return c}b={index:b,startSeconds:c,suggestedQuality:d};"string"===typeof a&&16===a.length?b.list="PL"+a:b.playlist=a;return b}
;function Zk(a){Sk.call(this);this.h=a;this.j=[];this.addEventListener("onReady",B(this.Za,this));this.addEventListener("onVideoProgress",B(this.jb,this));this.addEventListener("onVolumeChange",B(this.kb,this));this.addEventListener("onApiChange",B(this.eb,this));this.addEventListener("onPlaybackQualityChange",B(this.gb,this));this.addEventListener("onPlaybackRateChange",B(this.hb,this));this.addEventListener("onStateChange",B(this.ib,this));this.addEventListener("onWebglSettingsChanged",B(this.lb,
this))}
v(Zk,Sk);m=Zk.prototype;m.ra=function(a,b,c){if(this.h.isExternalMethodAvailable(a,c)){b=b||[];if(0<b.length&&Vk(a)){var d=b;if(Oa(d[0])&&!Array.isArray(d[0]))d=d[0];else{var e={};switch(a){case "loadVideoById":case "cueVideoById":e=Xk.apply(window,d);break;case "loadVideoByUrl":case "cueVideoByUrl":e=Wk.apply(window,d);break;case "loadPlaylist":case "cuePlaylist":e=Yk.apply(window,d)}d=e}b.length=1;b[0]=d}this.h.handleExternalCall(a,b,c);Vk(a)&&Uk(this,this.la())}};
m.Za=function(){var a=this.Na.bind(this);this.i.i=a};
m.addEventListener=function(a,b){this.j.push({eventType:a,listener:b});this.h.addEventListener(a,b)};
m.la=function(){if(!this.h)return null;var a=this.h.getApiInterface();eb(a,"getVideoData");for(var b={apiInterface:a},c=0,d=a.length;c<d;c++){var e=a[c];if(0===e.search("get")||0===e.search("is")){var f=0;0===e.search("get")?f=3:0===e.search("is")&&(f=2);f=e.charAt(f).toLowerCase()+e.substr(f+1);try{var g=this.h[e]();b[f]=g}catch(h){}}}b.videoData=this.h.getVideoData();b.currentTimeLastUpdated_=Date.now()/1E3;return b};
m.ib=function(a){a={playerState:a,currentTime:this.h.getCurrentTime(),duration:this.h.getDuration(),videoData:this.h.getVideoData(),videoStartBytes:0,videoBytesTotal:this.h.getVideoBytesTotal(),videoLoadedFraction:this.h.getVideoLoadedFraction(),playbackQuality:this.h.getPlaybackQuality(),availableQualityLevels:this.h.getAvailableQualityLevels(),currentTimeLastUpdated_:Date.now()/1E3,playbackRate:this.h.getPlaybackRate(),mediaReferenceTime:this.h.getMediaReferenceTime()};this.h.getVideoUrl&&(a.videoUrl=
this.h.getVideoUrl());this.h.getVideoContentRect&&(a.videoContentRect=this.h.getVideoContentRect());this.h.getProgressState&&(a.progressState=this.h.getProgressState());this.h.getPlaylist&&(a.playlist=this.h.getPlaylist());this.h.getPlaylistIndex&&(a.playlistIndex=this.h.getPlaylistIndex());this.h.getStoryboardFormat&&(a.storyboardFormat=this.h.getStoryboardFormat());Uk(this,a)};
m.gb=function(a){Uk(this,{playbackQuality:a})};
m.hb=function(a){Uk(this,{playbackRate:a})};
m.eb=function(){for(var a=this.h.getOptions(),b={namespaces:a},c=0,d=a.length;c<d;c++){var e=a[c],f=this.h.getOptions(e);b[e]={options:f};for(var g=0,h=f.length;g<h;g++){var k=f[g],l=this.h.getOption(e,k);b[e][k]=l}}this.sendMessage("apiInfoDelivery",b)};
m.kb=function(){Uk(this,{muted:this.h.isMuted(),volume:this.h.getVolume()})};
m.jb=function(a){a={currentTime:a,videoBytesLoaded:this.h.getVideoBytesLoaded(),videoLoadedFraction:this.h.getVideoLoadedFraction(),currentTimeLastUpdated_:Date.now()/1E3,playbackRate:this.h.getPlaybackRate(),mediaReferenceTime:this.h.getMediaReferenceTime()};this.h.getProgressState&&(a.progressState=this.h.getProgressState());Uk(this,a)};
m.lb=function(){var a={sphericalProperties:this.h.getSphericalProperties()};Uk(this,a)};
m.dispose=function(){Sk.prototype.dispose.call(this);for(var a=0;a<this.j.length;a++){var b=this.j[a];this.h.removeEventListener(b.eventType,b.listener)}this.j=[]};function $k(){var a=pb(al),b;return Le(new Ee(function(c,d){a.onSuccess=function(e){og(e)?c(new bl(e)):d(new cl("Request failed, status="+(e&&"status"in e?e.status:-1),"net.badstatus",e))};
a.onError=function(e){d(new cl("Unknown request error","net.unknown",e))};
a.onTimeout=function(e){d(new cl("Request timed out","net.timeout",e))};
b=ug("//googleads.g.doubleclick.net/pagead/id",a)}),function(c){c instanceof Me&&b.abort();
return Je(c)})}
function cl(a,b,c){Xa.call(this,a+", errorCode="+b);this.errorCode=b;this.xhr=c;this.name="PromiseAjaxError"}
v(cl,Xa);function bl(a){this.xhr=a}
;function dl(){this.i=0;this.h=null}
dl.prototype.then=function(a,b,c){return 1===this.i&&a?(a=a.call(c,this.h),De(a)?a:el(a)):2===this.i&&b?(a=b.call(c,this.h),De(a)?a:fl(a)):this};
dl.prototype.getValue=function(){return this.h};
dl.prototype.$goog_Thenable=!0;function fl(a){var b=new dl;a=void 0===a?null:a;b.i=2;b.h=void 0===a?null:a;return b}
function el(a){var b=new dl;a=void 0===a?null:a;b.i=1;b.h=void 0===a?null:a;return b}
;function gl(a){Xa.call(this,a.message||a.description||a.name);this.isMissing=a instanceof hl;this.isTimeout=a instanceof cl&&"net.timeout"==a.errorCode;this.isCanceled=a instanceof Me}
v(gl,Xa);gl.prototype.name="BiscottiError";function hl(){Xa.call(this,"Biscotti ID is missing from server")}
v(hl,Xa);hl.prototype.name="BiscottiMissingError";var al={format:"RAW",method:"GET",timeout:5E3,withCredentials:!0},il=null;function Zf(){if(Q("condition_biscotti_fetch_on_consent_cookie_html5_clients")&&!ed.get("CONSENT","").startsWith("YES+"))return Je(Error("User has not consented - not fetching biscotti id."));if("1"==nb())return Je(Error("Biscotti ID is not available in private embed mode"));il||(il=Le($k().then(jl),function(a){return kl(2,a)}));
return il}
function jl(a){a=a.xhr.responseText;if(0!=a.lastIndexOf(")]}'",0))throw new hl;a=JSON.parse(a.substr(4));if(1<(a.type||1))throw new hl;a=a.id;$f(a);il=el(a);ll(18E5,2);return a}
function kl(a,b){b=new gl(b);$f("");il=fl(b);0<a&&ll(12E4,a-1);throw b;}
function ll(a,b){Jf(function(){Le($k().then(jl,function(c){return kl(b,c)}),Ka)},a)}
function ml(){try{var a=A("yt.ads.biscotti.getId_");return a?a():Zf()}catch(b){return Je(b)}}
;function nl(a){if("1"!=nb()){a&&Yf();try{ml().then(function(){},function(){}),Jf(nl,18E5)}catch(b){sf(b)}}}
;var ol=Date.now().toString();
function pl(){a:{if(window.crypto&&window.crypto.getRandomValues)try{var a=Array(16),b=new Uint8Array(16);window.crypto.getRandomValues(b);for(var c=0;c<a.length;c++)a[c]=b[c];var d=a;break a}catch(e){}d=Array(16);for(a=0;16>a;a++){b=Date.now();for(c=0;c<b%23;c++)d[a]=Math.random();d[a]=Math.floor(256*Math.random())}if(ol)for(a=1,b=0;b<ol.length;b++)d[a%16]=d[a%16]^d[(a-1)%16]/4^ol.charCodeAt(b),a++}a=[];for(b=0;b<d.length;b++)a.push("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_".charAt(d[b]&63));
return a.join("")}
;var ql,rl=y.ytLoggingDocDocumentNonce_;rl||(rl=pl(),Va("ytLoggingDocDocumentNonce_",rl));ql=rl;var sl={be:0,Zb:1,jc:2,hh:3,de:4,mk:5,Uh:6,Wi:7,0:"DEFAULT",1:"CHAT",2:"CONVERSATIONS",3:"MINIPLAYER",4:"DIALOG",5:"VOZ",6:"MUSIC_WATCH_TABS",7:"SHARE"};function tl(a){this.h=a}
function ul(a){return new tl({trackingParams:a})}
tl.prototype.getAsJson=function(){var a={};void 0!==this.h.trackingParams?a.trackingParams=this.h.trackingParams:(a.veType=this.h.veType,void 0!==this.h.veCounter&&(a.veCounter=this.h.veCounter),void 0!==this.h.elementIndex&&(a.elementIndex=this.h.elementIndex));void 0!==this.h.dataElement&&(a.dataElement=this.h.dataElement.getAsJson());void 0!==this.h.youtubeData&&(a.youtubeData=this.h.youtubeData);return a};
tl.prototype.toString=function(){return JSON.stringify(this.getAsJson())};
tl.prototype.isClientVe=function(){return!this.h.trackingParams&&!!this.h.veType};function vl(a){a=void 0===a?0:a;return 0==a?"client-screen-nonce":"client-screen-nonce."+a}
function wl(a){a=void 0===a?0:a;return 0==a?"ROOT_VE_TYPE":"ROOT_VE_TYPE."+a}
function xl(a){return F(wl(void 0===a?0:a),void 0)}
z("yt_logging_screen.getRootVeType",xl,void 0);function yl(a){return(a=xl(void 0===a?0:a))?new tl({veType:a,youtubeData:void 0}):null}
function zl(){var a=F("csn-to-ctt-auth-info");a||(a={},N("csn-to-ctt-auth-info",a));return a}
function Al(a){a=void 0===a?0:a;var b=F(vl(a));if(!b&&!F("USE_CSN_FALLBACK",!0))return null;b||0!=a||(b="UNDEFINED_CSN");return b?b:null}
z("yt_logging_screen.getCurrentCsn",Al,void 0);function Bl(a,b,c){var d=zl();(c=Al(c))&&delete d[c];b&&(d[a]=b)}
function Cl(a){return zl()[a]}
z("yt_logging_screen.getCttAuthInfo",Cl,void 0);function Dl(a,b,c,d){c=void 0===c?0:c;if(a!==F(vl(c))||b!==F(wl(c)))Bl(a,d,c),N(vl(c),a),N(wl(c),b),b=function(){setTimeout(function(){a&&rh("foregroundHeartbeatScreenAssociated",{clientDocumentNonce:ql,clientScreenNonce:a},vk)},0)},"requestAnimationFrame"in window?window.requestAnimationFrame(b):b()}
z("yt_logging_screen.setCurrentScreen",Dl,void 0);function El(a){Lh.call(this,1,arguments);this.csn=a}
v(El,Lh);var Uh=new Mh("screen-created",El),Fl=[],Hl=Gl,Il=0;function Jl(a,b,c,d){var e=d;Q("web_dedupe_ve_grafting")&&(e=d.filter(function(f){f.csn!==b?(f.csn=b,f=!0):f=!1;return f}));
c={csn:b,parentVe:c.getAsJson(),childVes:bb(e,function(f){return f.getAsJson()})};
d=u(d);for(e=d.next();!e.done;e=d.next())e=e.value.getAsJson(),(kb(e)||!e.trackingParams&&!e.veType)&&Nk(Error("Child VE logged with no data"));d={G:Cl(b),P:b};"UNDEFINED_CSN"==b?Kl("visualElementAttached",c,d):a?rh("visualElementAttached",c,a,d):wk("visualElementAttached",c,d)}
function Gl(){for(var a=Math.random()+"",b=[],c=0,d=0;d<a.length;d++){var e=a.charCodeAt(d);255<e&&(b[c++]=e&255,e>>=8);b[c++]=e}return Ec(b)}
function Kl(a,b,c){Fl.push({payloadName:a,payload:b,options:c});Il||(Il=Vh())}
function Wh(a){if(Fl){for(var b=u(Fl),c=b.next();!c.done;c=b.next())c=c.value,c.payload&&(c.payload.csn=a.csn,rh(c.payloadName,c.payload,null,c.options));Fl.length=0}Il=0}
;function Ll(){this.i=new Set;this.h=new Set;this.j=new Map}
Ll.prototype.clear=function(){this.i.clear();this.h.clear();this.j.clear()};
La(Ll);function Ml(a,b){for(var c=[],d=1;d<arguments.length;++d)c[d-1]=arguments[d];if(!Nl(a)||c.some(function(e){return!Nl(e)}))throw Error("Only objects may be merged.");
c=u(c);for(d=c.next();!d.done;d=c.next())Ol(a,d.value);return a}
function Ol(a,b){for(var c in b)if(Nl(b[c])){if(c in a&&!Nl(a[c]))throw Error("Cannot merge an object into a non-object.");c in a||(a[c]={});Ol(a[c],b[c])}else if(Pl(b[c])){if(c in a&&!Pl(a[c]))throw Error("Cannot merge an array into a non-array.");c in a||(a[c]=[]);Ql(a[c],b[c])}else a[c]=b[c];return a}
function Ql(a,b){b=u(b);for(var c=b.next();!c.done;c=b.next())c=c.value,Nl(c)?a.push(Ol({},c)):Pl(c)?a.push(Ql([],c)):a.push(c);return a}
function Nl(a){return"object"===typeof a&&!Array.isArray(a)}
function Pl(a){return"object"===typeof a&&Array.isArray(a)}
;function Rl(a,b){Lh.call(this,1,arguments)}
v(Rl,Lh);function Sl(a,b){Lh.call(this,1,arguments)}
v(Sl,Lh);var Tl=new Mh("aft-recorded",Rl),Ul=new Mh("timing-sent",Sl);var Vl=window;function Wl(){this.timing={};this.clearResourceTimings=function(){};
this.webkitClearResourceTimings=function(){};
this.mozClearResourceTimings=function(){};
this.msClearResourceTimings=function(){};
this.oClearResourceTimings=function(){}}
var W=Vl.performance||Vl.mozPerformance||Vl.msPerformance||Vl.webkitPerformance||new Wl;var Xl=!1,Yl={'script[name="scheduler/scheduler"]':"sj",'script[name="player/base"]':"pj",'link[rel="stylesheet"][name="www-player"]':"pc",'link[rel="stylesheet"][name="player/www-player"]':"pc",'script[name="desktop_polymer/desktop_polymer"]':"dpj",'link[rel="import"][name="desktop_polymer"]':"dph",'script[name="mobile-c3/mobile-c3"]':"mcj",'link[rel="stylesheet"][name="mobile-c3"]':"mcc",'script[name="player-plasma-ias-phone/base"]':"mcppj",'script[name="player-plasma-ias-tablet/base"]':"mcptj",
'link[rel="stylesheet"][name="mobile-polymer-player-ias"]':"mcpc",'link[rel="stylesheet"][name="mobile-polymer-player-svg-ias"]':"mcpsc",'script[name="mobile_blazer_core_mod"]':"mbcj",'link[rel="stylesheet"][name="mobile_blazer_css"]':"mbc",'script[name="mobile_blazer_logged_in_users_mod"]':"mbliuj",'script[name="mobile_blazer_logged_out_users_mod"]':"mblouj",'script[name="mobile_blazer_noncore_mod"]':"mbnj","#player_css":"mbpc",'script[name="mobile_blazer_desktopplayer_mod"]':"mbpj",'link[rel="stylesheet"][name="mobile_blazer_tablet_css"]':"mbtc",
'script[name="mobile_blazer_watch_mod"]':"mbwj"};B(W.clearResourceTimings||W.webkitClearResourceTimings||W.mozClearResourceTimings||W.msClearResourceTimings||W.oClearResourceTimings||Ka,W);function Zl(a){var b=$l(a);if(b.aft)return b.aft;a=F((a||"")+"TIMING_AFT_KEYS",["ol"]);for(var c=a.length,d=0;d<c;d++){var e=b[a[d]];if(e)return e}return NaN}
function am(){var a;if(Q("csi_use_performance_navigation_timing")){var b,c,d,e=null===(d=null===(c=null===(b=null===(a=null===W||void 0===W?void 0:W.getEntriesByType)||void 0===a?void 0:a.call(W,"navigation"))||void 0===b?void 0:b[0])||void 0===c?void 0:c.toJSON)||void 0===d?void 0:d.call(c);e?(e.requestStart=bm(e.requestStart),e.responseEnd=bm(e.responseEnd),e.redirectStart=bm(e.redirectStart),e.redirectEnd=bm(e.redirectEnd),e.domainLookupEnd=bm(e.domainLookupEnd),e.connectStart=bm(e.connectStart),
e.connectEnd=bm(e.connectEnd),e.responseStart=bm(e.responseStart),e.secureConnectionStart=bm(e.secureConnectionStart),e.domainLookupStart=bm(e.domainLookupStart),e.isPerformanceNavigationTiming=!0,a=e):a=W.timing}else a=W.timing;return a}
function cm(){return Q("csi_use_time_origin")&&W.timeOrigin?Math.floor(W.timeOrigin):W.timing.navigationStart}
function bm(a){return Math.round(cm()+a)}
function dm(a){var b;(b=A("ytcsi."+(a||"")+"data_"))||(b={tick:{},info:{}},Va("ytcsi."+(a||"")+"data_",b));return b}
function em(a){a=dm(a);a.info||(a.info={});return a.info}
function $l(a){a=dm(a);a.tick||(a.tick={});return a.tick}
function fm(a){var b=dm(a).nonce;b||(b=pl(),dm(a).nonce=b);return b}
function gm(a){var b=$l(a||""),c=Zl(a);c&&!Xl&&(Rh(Tl,new Rl(Math.round(c-b._start),a)),Xl=!0)}
;function hm(){if(W.getEntriesByType){var a=W.getEntriesByType("paint");if(a=db(a,function(b){return"first-paint"===b.name}))return bm(a.startTime)}a=W.timing;
return a.Ya?Math.max(0,a.Ya):0}
;function im(){var a=A("ytcsi.debug");a||(a=[],z("ytcsi.debug",a,void 0),z("ytcsi.reference",{},void 0));return a}
function jm(a){a=a||"";var b=A("ytcsi.reference");b||(im(),b=A("ytcsi.reference"));if(b[a])return b[a];var c=im(),d={timerName:a,info:{},tick:{},span:{}};c.push(d);return b[a]=d}
;var km=y.ytLoggingLatencyUsageStats_||{};z("ytLoggingLatencyUsageStats_",km,void 0);function lm(){this.h=0}
function mm(){lm.h||(lm.h=new lm);return lm.h}
lm.prototype.tick=function(a,b,c){nm(this,"tick_"+a+"_"+b)||wk("latencyActionTicked",{tickName:a,clientActionNonce:b},{timestamp:c})};
lm.prototype.info=function(a,b){var c=Object.keys(a).join("");nm(this,"info_"+c+"_"+b)||(a=Object.assign({},a),a.clientActionNonce=b,wk("latencyActionInfo",a))};
lm.prototype.span=function(a,b){var c=Object.keys(a).join("");nm(this,"span_"+c+"_"+b)||(a.clientActionNonce=b,wk("latencyActionSpan",a))};
function nm(a,b){km[b]=km[b]||{count:0};var c=km[b];c.count++;c.time=R();a.h||(a.h=Nf(function(){var d=R(),e;for(e in km)km[e]&&6E4<d-km[e].time&&delete km[e];a&&(a.h=0)},5E3));
return 5<c.count?(6===c.count&&1>1E5*Math.random()&&(c=new hi("CSI data exceeded logging limit with key",b.split("_")),0<=b.indexOf("plev")||Nk(c)),!0):!1}
;var X={},om=(X.auto_search="LATENCY_ACTION_AUTO_SEARCH",X.ad_to_ad="LATENCY_ACTION_AD_TO_AD",X.ad_to_video="LATENCY_ACTION_AD_TO_VIDEO",X.app_startup="LATENCY_ACTION_APP_STARTUP",X["artist.analytics"]="LATENCY_ACTION_CREATOR_ARTIST_ANALYTICS",X["artist.events"]="LATENCY_ACTION_CREATOR_ARTIST_CONCERTS",X["artist.presskit"]="LATENCY_ACTION_CREATOR_ARTIST_PROFILE",X.browse="LATENCY_ACTION_BROWSE",X.channels="LATENCY_ACTION_CHANNELS",X.creator_channel_dashboard="LATENCY_ACTION_CREATOR_CHANNEL_DASHBOARD",
X["channel.analytics"]="LATENCY_ACTION_CREATOR_CHANNEL_ANALYTICS",X["channel.comments"]="LATENCY_ACTION_CREATOR_CHANNEL_COMMENTS",X["channel.content"]="LATENCY_ACTION_CREATOR_POST_LIST",X["channel.copyright"]="LATENCY_ACTION_CREATOR_CHANNEL_COPYRIGHT",X["channel.editing"]="LATENCY_ACTION_CREATOR_CHANNEL_EDITING",X["channel.monetization"]="LATENCY_ACTION_CREATOR_CHANNEL_MONETIZATION",X["channel.music"]="LATENCY_ACTION_CREATOR_CHANNEL_MUSIC",X["channel.translations"]="LATENCY_ACTION_CREATOR_CHANNEL_TRANSLATIONS",
X["channel.videos"]="LATENCY_ACTION_CREATOR_CHANNEL_VIDEOS",X["channel.live_streaming"]="LATENCY_ACTION_CREATOR_LIVE_STREAMING",X.chips="LATENCY_ACTION_CHIPS",X["dialog.copyright_strikes"]="LATENCY_ACTION_CREATOR_DIALOG_COPYRIGHT_STRIKES",X["dialog.uploads"]="LATENCY_ACTION_CREATOR_DIALOG_UPLOADS",X.embed="LATENCY_ACTION_EMBED",X.entity_key_serialization_perf="LATENCY_ACTION_ENTITY_KEY_SERIALIZATION_PERF",X.entity_key_deserialization_perf="LATENCY_ACTION_ENTITY_KEY_DESERIALIZATION_PERF",X.home="LATENCY_ACTION_HOME",
X.library="LATENCY_ACTION_LIBRARY",X.live="LATENCY_ACTION_LIVE",X.live_pagination="LATENCY_ACTION_LIVE_PAGINATION",X.onboarding="LATENCY_ACTION_KIDS_ONBOARDING",X.parent_profile_settings="LATENCY_ACTION_KIDS_PARENT_PROFILE_SETTINGS",X.parent_tools_collection="LATENCY_ACTION_PARENT_TOOLS_COLLECTION",X.parent_tools_dashboard="LATENCY_ACTION_PARENT_TOOLS_DASHBOARD",X.player_att="LATENCY_ACTION_PLAYER_ATTESTATION",X["post.comments"]="LATENCY_ACTION_CREATOR_POST_COMMENTS",X["post.edit"]="LATENCY_ACTION_CREATOR_POST_EDIT",
X.prebuffer="LATENCY_ACTION_PREBUFFER",X.prefetch="LATENCY_ACTION_PREFETCH",X.profile_settings="LATENCY_ACTION_KIDS_PROFILE_SETTINGS",X.profile_switcher="LATENCY_ACTION_KIDS_PROFILE_SWITCHER",X.results="LATENCY_ACTION_RESULTS",X.search_ui="LATENCY_ACTION_SEARCH_UI",X.search_suggest="LATENCY_ACTION_SUGGEST",X.search_zero_state="LATENCY_ACTION_SEARCH_ZERO_STATE",X.secret_code="LATENCY_ACTION_KIDS_SECRET_CODE",X.seek="LATENCY_ACTION_PLAYER_SEEK",X.settings="LATENCY_ACTION_SETTINGS",X.tenx="LATENCY_ACTION_TENX",
X.video_to_ad="LATENCY_ACTION_VIDEO_TO_AD",X.watch="LATENCY_ACTION_WATCH",X.watch_it_again="LATENCY_ACTION_KIDS_WATCH_IT_AGAIN",X["watch,watch7"]="LATENCY_ACTION_WATCH",X["watch,watch7_html5"]="LATENCY_ACTION_WATCH",X["watch,watch7ad"]="LATENCY_ACTION_WATCH",X["watch,watch7ad_html5"]="LATENCY_ACTION_WATCH",X.wn_comments="LATENCY_ACTION_LOAD_COMMENTS",X.ww_rqs="LATENCY_ACTION_WHO_IS_WATCHING",X["video.analytics"]="LATENCY_ACTION_CREATOR_VIDEO_ANALYTICS",X["video.comments"]="LATENCY_ACTION_CREATOR_VIDEO_COMMENTS",
X["video.edit"]="LATENCY_ACTION_CREATOR_VIDEO_EDIT",X["video.translations"]="LATENCY_ACTION_CREATOR_VIDEO_TRANSLATIONS",X["video.video_editor"]="LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR",X["video.video_editor_async"]="LATENCY_ACTION_CREATOR_VIDEO_VIDEO_EDITOR_ASYNC",X["video.monetization"]="LATENCY_ACTION_CREATOR_VIDEO_MONETIZATION",X.voice_assistant="LATENCY_ACTION_VOICE_ASSISTANT",X.cast_load_by_entity_to_watch="LATENCY_ACTION_CAST_LOAD_BY_ENTITY_TO_WATCH",X.networkless_performance="LATENCY_ACTION_NETWORKLESS_PERFORMANCE",
X),Y={},pm=(Y.ad_allowed="adTypesAllowed",Y.yt_abt="adBreakType",Y.ad_cpn="adClientPlaybackNonce",Y.ad_docid="adVideoId",Y.yt_ad_an="adNetworks",Y.ad_at="adType",Y.aida="appInstallDataAgeMs",Y.browse_id="browseId",Y.p="httpProtocol",Y.t="transportProtocol",Y.cpn="clientPlaybackNonce",Y.ccs="creatorInfo.creatorCanaryState",Y.csn="clientScreenNonce",Y.docid="videoId",Y.GetHome_rid="requestIds",Y.GetSearch_rid="requestIds",Y.GetPlayer_rid="requestIds",Y.GetWatchNext_rid="requestIds",Y.GetBrowse_rid=
"requestIds",Y.GetLibrary_rid="requestIds",Y.is_continuation="isContinuation",Y.is_nav="isNavigation",Y.b_p="kabukiInfo.browseParams",Y.is_prefetch="kabukiInfo.isPrefetch",Y.is_secondary_nav="kabukiInfo.isSecondaryNav",Y.prev_browse_id="kabukiInfo.prevBrowseId",Y.query_source="kabukiInfo.querySource",Y.voz_type="kabukiInfo.vozType",Y.yt_lt="loadType",Y.mver="creatorInfo.measurementVersion",Y.yt_ad="isMonetized",Y.nr="webInfo.navigationReason",Y.nrsu="navigationRequestedSameUrl",Y.ncnp="webInfo.nonPreloadedNodeCount",
Y.pnt="performanceNavigationTiming",Y.prt="playbackRequiresTap",Y.plt="playerInfo.playbackType",Y.pis="playerInfo.playerInitializedState",Y.paused="playerInfo.isPausedOnLoad",Y.yt_pt="playerType",Y.fmt="playerInfo.itag",Y.yt_pl="watchInfo.isPlaylist",Y.yt_pre="playerInfo.preloadType",Y.yt_ad_pr="prerollAllowed",Y.pa="previousAction",Y.yt_red="isRedSubscriber",Y.rce="mwebInfo.responseContentEncoding",Y.scrh="screenHeight",Y.scrw="screenWidth",Y.st="serverTimeMs",Y.ssdm="shellStartupDurationMs",Y.br_trs=
"tvInfo.bedrockTriggerState",Y.kebqat="kabukiInfo.earlyBrowseRequestInfo.abandonmentType",Y.kebqa="kabukiInfo.earlyBrowseRequestInfo.adopted",Y.label="tvInfo.label",Y.is_mdx="tvInfo.isMdx",Y.preloaded="tvInfo.isPreloaded",Y.upg_player_vis="playerInfo.visibilityState",Y.query="unpluggedInfo.query",Y.upg_chip_ids_string="unpluggedInfo.upgChipIdsString",Y.yt_vst="videoStreamType",Y.vph="viewportHeight",Y.vpw="viewportWidth",Y.yt_vis="isVisible",Y.rcl="mwebInfo.responseContentLength",Y.GetSettings_rid=
"requestIds",Y.GetTrending_rid="requestIds",Y.GetMusicSearchSuggestions_rid="requestIds",Y.REQUEST_ID="requestIds",Y),qm="isContinuation isNavigation kabukiInfo.earlyBrowseRequestInfo.adopted kabukiInfo.isPrefetch kabukiInfo.isSecondaryNav isMonetized navigationRequestedSameUrl performanceNavigationTiming playerInfo.isPausedOnLoad prerollAllowed isRedSubscriber tvInfo.isMdx tvInfo.isPreloaded isVisible watchInfo.isPlaylist playbackRequiresTap".split(" "),rm={},sm=(rm.ccs="CANARY_STATE_",rm.mver="MEASUREMENT_VERSION_",
rm.pis="PLAYER_INITIALIZED_STATE_",rm.yt_pt="LATENCY_PLAYER_",rm.pa="LATENCY_ACTION_",rm.yt_vst="VIDEO_STREAM_TYPE_",rm),tm="all_vc ap aq c cver cbrand cmodel cplatform ctheme ei l_an l_mm plid srt yt_fss yt_li vpst vpni2 vpil2 icrc icrt pa GetAccountOverview_rid GetHistory_rid cmt d_vpct d_vpnfi d_vpni nsru pc pfa pfeh pftr pnc prerender psc rc start tcrt tcrc ssr vpr vps yt_abt yt_fn yt_fs yt_pft yt_pre yt_pt yt_pvis ytu_pvis yt_ref yt_sts tds".split(" ");
function um(a){return!!F("FORCE_CSI_ON_GEL",!1)||Q("csi_on_gel")||!!dm(a).useGel}
function vm(a,b,c){var d=wm(c);d.gelTicks&&(d.gelTicks["tick_"+a]=!0);c||b||R();return um(c)?(jm(c||"").tick[a]=b||R(),d=fm(c),"_start"===a?(a=mm(),nm(a,"baseline_"+d)||wk("latencyActionBaselined",{clientActionNonce:d},{timestamp:b})):mm().tick(a,d,b),gm(c),!0):!1}
function xm(a,b,c){c=wm(c);if(c.gelInfos)c.gelInfos["info_"+a]=!0;else{var d={};c.gelInfos=(d["info_"+a]=!0,d)}if(a.match("_rid")){var e=a.split("_rid")[0];a="REQUEST_ID"}if(a in pm){c=pm[a];0<=$a(qm,c)&&(b=!!b);a in sm&&"string"===typeof b&&(b=sm[a]+b.toUpperCase());a=b;b=c.split(".");for(var f=d={},g=0;g<b.length-1;g++){var h=b[g];f[h]={};f=f[h]}f[b[b.length-1]]="requestIds"===c?[{id:a,endpoint:e}]:a;return Ml({},d)}0<=$a(tm,a)||Nk(new hi("Unknown label logged with GEL CSI",a))}
function wm(a){a=dm(a);if(a.gel){var b=a.gel;b.gelInfos||(b.gelInfos={});b.gelTicks||(b.gelTicks={})}else a.gel={gelTicks:{},gelInfos:{}};return a.gel}
function ym(a){a=wm(a);a.gelInfos||(a.gelInfos={});return a.gelInfos}
;function zm(a,b,c){null!==b&&(em(c)[a]=b,um(c)?(a=xm(a,b,c))&&um(c)&&(b=jm(c||""),Ml(b.info,a),Ml(ym(c),a),c=fm(c),mm().info(a,c)):jm(c||"").info[a]=b)}
function Z(a,b,c){var d=$l(c);if(!b&&"_"!==a[0]){var e=a;W.mark&&(0==e.lastIndexOf("mark_",0)||(e="mark_"+e),c&&(e+=" ("+c+")"),W.mark(e))}e=b||R();d[a]=e;vm(a,b,c)||(Am(c),jm(c||"").tick[a]=b||R());return d[a]}
function Bm(a,b){if(um(void 0)){var c=wm(void 0);if(c.gelSpans)c.gelSpans[a]=!0;else{var d={};c.gelSpans=(d[a]=!0,d)}a={spanName:a,spanLengthUsec:String(Math.round(1E3*b))};jm("").span[String(a.spanName)]=a;b=wm(void 0);b.gelSpans||(b.gelSpans={});Ml(b.gelSpans,a);b=fm(void 0);mm().span(a,b)}}
function Cm(){var a=fm(void 0);requestAnimationFrame(function(){setTimeout(function(){a===fm(void 0)&&Z("ol",void 0,void 0)},0)})}
function Am(a){if(!A("yt.timing."+(a||"")+"pingSent_")){var b=F((a||"")+"TIMING_ACTION",void 0),c=$l(a);if(b=!!A("ytglobal.timing"+(a||"")+"ready_")&&b)b="_start"in $l(void 0);if(b&&Zl(a))if(gm(a),a)Dm(a);else{b=!0;var d=F("TIMING_WAIT",[]);if(d.length)for(var e=0,f=d.length;e<f;++e)if(!(d[e]in c)){b=!1;break}b&&Dm(a)}}}
function Em(){var a=document;if("visibilityState"in a)a=a.visibilityState;else{var b=zf+"VisibilityState";a=b in a?a[b]:void 0}switch(a){case "hidden":return 0;case "visible":return 1;case "prerender":return 2;case "unloaded":return 3;default:return-1}}
function Dm(a){if(!um(a)){var b=$l(a),c=em(a),d=b._start,e=F("CSI_SERVICE_NAME","youtube"),f={v:2,s:e,action:F((a||"")+"TIMING_ACTION",void 0)},g=c.srt;void 0!==b.srt&&delete c.srt;b.aft=Zl(a);var h=$l(a),k=h.pbr,l=h.vc;h=h.pbs;k&&l&&h&&k<l&&l<h&&em(a).yt_pvis&&"youtube"===e&&(zm("yt_lt","hot_bg",a),e=b.vc,k=b.pbs,delete b.aft,c.aft=Math.round(k-e));for(var p in c)"_"!==p.charAt(0)&&(f[p]=c[p]);b.ps=R();p={};e=[];for(var n in b)"_"!==n.charAt(0)&&(k=Math.round(b[n]-d),p[n]=k,e.push(n+"."+k));f.rt=
e.join(",");b=!!c.ap;c="";for(var r in f)f.hasOwnProperty(r)&&(c+="&"+r+"="+f[r]);f="/csi_204?"+c.substring(1);window.navigator&&window.navigator.sendBeacon&&(b||Q("always_send_csi_204_with_beacon"))?Jg(f):Gg(f);z("yt.timing."+(a||"")+"pingSent_",!0,void 0);Rh(Ul,new Sl(p.aft+(Number(g)||0),a))}}
function Fm(a,b){a=document.querySelector(a);if(!a)return!1;var c="",d=a.nodeName;"SCRIPT"===d?(c=a.src,c||(c=a.getAttribute("data-timing-href"))&&(c=window.location.protocol+c)):"LINK"===d&&(c=a.href);Ga()&&a.setAttribute("nonce",Ga());return c?(a=W.getEntriesByName(c))&&a[0]&&(a=a[0],c=cm(),Z("rsf_"+b,c+Math.round(a.fetchStart)),Z("rse_"+b,c+Math.round(a.responseEnd)),void 0!==a.transferSize&&(b=em(void 0),c=ym(void 0),"rc"in b||"rc"in c||zm("rc",""),0===a.transferSize))?!0:!1:!1}
function Gm(){var a=window.location.protocol,b=W.getEntriesByType("resource");b=ab(b,function(c){return 0===c.name.indexOf(a+"//fonts.gstatic.com/s/")});
(b=cb(b,function(c,d){return d.duration>c.duration?d:c},{duration:0}))&&0<b.startTime&&0<b.responseEnd&&(Z("wffs",bm(b.startTime)),Z("wffe",bm(b.responseEnd)))}
var Hm=window;Hm.ytcsi&&(Hm.ytcsi.info=zm,Hm.ytcsi.tick=Z);function Im(){this.l=[];this.u=[];this.h=[];this.i=new Set;this.m=new Map}
function Jm(a,b,c){c=void 0===c?0:c;b.then(function(d){var e,f;a.i.has(c)&&a.j&&a.j();var g=Al(c),h=yl(c);g&&h&&(d.csn=g,(null===(e=d.response)||void 0===e?0:e.trackingParams)&&Jl(a.client,g,h,[ul(d.response.trackingParams)]),(null===(f=d.playerResponse)||void 0===f?0:f.trackingParams)&&Jl(a.client,g,h,[ul(d.playerResponse.trackingParams)]))})}
function Km(a,b,c,d){d=void 0===d?0:d;if(a.i.has(d))a.l.push([b,c]);else{var e=Al(d);c=c||yl(d);e&&c&&Jl(a.client,e,c,[b])}}
Im.prototype.clickCommand=function(a,b,c){c=Al(void 0===c?0:c);if(!a.clickTrackingParams||!c)return!1;var d=this.client;var e="INTERACTION_LOGGING_GESTURE_TYPE_GENERIC_CLICK";a={csn:c,ve:ul(a.clickTrackingParams).getAsJson(),gestureType:e};b&&(a.clientData=b);b={G:Cl(c),P:c};"UNDEFINED_CSN"==c?Kl("visualElementGestured",a,b):d?rh("visualElementGestured",a,d,b):wk("visualElementGestured",a,b);return!0};
function Lm(a,b,c){c=void 0===c?{}:c;a.i.add(c.layer||0);a.j=function(){Mm(a,b,c);var f=yl(c.layer);if(f){for(var g=u(a.l),h=g.next();!h.done;h=g.next())h=h.value,Km(a,h[0],h[1]||f,c.layer);f=u(a.u);for(g=f.next();!g.done;g=f.next()){var k=g.value;g=void 0;g=void 0===g?0:g;h=Al(g);var l=k[0]||yl(g);h&&l&&(g=a.client,k=k[1],k={csn:h,ve:l.getAsJson(),clientData:k},l={G:Cl(h),P:h},"UNDEFINED_CSN"==h?Kl("visualElementStateChanged",k,l):g?rh("visualElementStateChanged",k,g,l):wk("visualElementStateChanged",
k,l))}}};
Al(c.layer)||a.j();if(c.wa)for(var d=u(c.wa),e=d.next();!e.done;e=d.next())Jm(a,e.value,c.layer);else Ok(Error("Delayed screen needs a data promise."))}
function Mm(a,b,c){c=void 0===c?{}:c;c.layer||(c.layer=0);var d=void 0!==c.ab?c.ab:c.layer;var e=Al(d);d=yl(d);var f;d&&(void 0!==c.parentCsn?f={clientScreenNonce:c.parentCsn,visualElement:d}:e&&"UNDEFINED_CSN"!==e&&(f={clientScreenNonce:e,visualElement:d}));try{var g=a.client,h=f,k=c.va,l=c.G,p=Hl(),n={csn:p,pageVe:(new tl({veType:b,youtubeData:void 0})).getAsJson()};h&&h.visualElement?n.implicitGesture={parentCsn:h.clientScreenNonce,gesturedVe:h.visualElement.getAsJson()}:h&&Nk(new hi("newScreen() parent element does not have a VE - rootVe",
b));k&&(n.cloneCsn=k);k={G:l,P:p};g?rh("screenCreated",n,g,k):wk("screenCreated",n,k);Rh(Uh,new El(p));var r=p}catch(q){Pk(q,{Ok:b,rootVe:d,parentVisualElement:void 0,Jk:e,Nk:f,va:c.va});Ok(q);return}Dl(r,b,c.layer,c.G);if((b=e&&"UNDEFINED_CSN"!==e&&d)&&!(b=Q("screen_manager_skip_hide_killswitch"))){a:{b=u(Object.values(sl));for(f=b.next();!f.done;f=b.next())if(Al(f.value)==e){b=!0;break a}b=!1}b=!b}b&&(b=a.client,f=!0,g=(f=void 0===f?!1:f)?16:8,d={csn:e,ve:d.getAsJson(),eventType:g},f={G:Cl(e),P:e,
Ma:f},"UNDEFINED_CSN"==e?Kl("visualElementHidden",d,f):b?rh("visualElementHidden",d,b,f):wk("visualElementHidden",d,f));a.h[a.h.length-1]&&!a.h[a.h.length-1].csn&&(a.h[a.h.length-1].csn=r||"");zm("csn",r);Ll.getInstance().clear();d=yl(c.layer);e&&"UNDEFINED_CSN"!==e&&d&&(Q("web_mark_root_visible")||Q("music_web_mark_root_visible"))&&(e=r,r=Q("use_default_events_client")?void 0:vk,b={csn:e,ve:d.getAsJson(),eventType:1},f={G:Cl(e),P:e},"UNDEFINED_CSN"==e?Kl("visualElementShown",b,f):r?rh("visualElementShown",
b,r,f):wk("visualElementShown",b,f));a.i.delete(c.layer||0);a.j=void 0;e=u(a.m);for(r=e.next();!r.done;r=e.next())r=u(r.value),b=r.next().value,r.next().value.has(c.layer)&&d&&Km(a,b,d,c.layer)}
;function Nm(a){a&&(a.dataset?a.dataset[Om("loaded")]="true":a.setAttribute("data-loaded","true"))}
function Pm(a,b){return a?a.dataset?a.dataset[Om(b)]:a.getAttribute("data-"+b):null}
var Qm={};function Om(a){return Qm[a]||(Qm[a]=String(a).replace(/\-([a-z])/g,function(b,c){return c.toUpperCase()}))}
;var Rm=/\.vflset|-vfl[a-zA-Z0-9_+=-]+/,Sm=/-[a-zA-Z]{2,3}_[a-zA-Z]{2,3}(?=(\/|$))/;function Tm(a,b,c){c=void 0===c?null:c;if(window.spf&&spf.script){c="";if(a){var d=a.indexOf("jsbin/"),e=a.lastIndexOf(".js"),f=d+6;-1<d&&-1<e&&e>f&&(c=a.substring(f,e),c=c.replace(Rm,""),c=c.replace(Sm,""),c=c.replace("debug-",""),c=c.replace("tracing-",""))}spf.script.load(a,c,b)}else Um(a,b,c)}
function Um(a,b,c){c=void 0===c?null:c;var d=Vm(a),e=document.getElementById(d),f=e&&Pm(e,"loaded"),g=e&&!f;f?b&&b():(b&&(f=Og(d,b),b=""+Pa(b),Wm[b]=f),g||(e=Xm(a,d,function(){Pm(e,"loaded")||(Nm(e),Rg(d),Jf(Ua(Sg,d),0))},c)))}
function Xm(a,b,c,d){d=void 0===d?null:d;var e=Mc(document,"SCRIPT");e.id=b;e.onload=function(){c&&setTimeout(c,0)};
e.onreadystatechange=function(){switch(e.readyState){case "loaded":case "complete":e.onload()}};
d&&e.setAttribute("nonce",d);Zb(e,Uc(a));a=document.getElementsByTagName("head")[0]||document.body;a.insertBefore(e,a.firstChild);return e}
function Ym(a){a=Vm(a);var b=document.getElementById(a);b&&(Sg(a),b.parentNode.removeChild(b))}
function Zm(a,b){a&&b&&(a=""+Pa(b),(a=Wm[a])&&Qg(a))}
function Vm(a){var b=document.createElement("a");Vb(b,a);a=b.href.replace(/^[a-zA-Z]+:\/\//,"//");return"js-"+bc(a)}
var Wm={};var $m=[],an=!1;function bn(){if((!Q("condition_ad_status_fetch_on_consent_cookie_html5_clients")||ed.get("CONSENT","").startsWith("YES+"))&&"1"!=nb()){var a=function(){an=!0;"google_ad_status"in window?N("DCLKSTAT",1):N("DCLKSTAT",2)};
try{Tm("//static.doubleclick.net/instream/ad_status.js",a)}catch(b){}$m.push(Pf(function(){if(!(an||"google_ad_status"in window)){try{Zm("//static.doubleclick.net/instream/ad_status.js",a)}catch(b){}an=!0;N("DCLKSTAT",3)}},5E3))}}
function cn(){var a=Number(F("DCLKSTAT",0));return isNaN(a)?0:a}
;function dn(){this.i=!1;this.h=null}
dn.prototype.initialize=function(a,b,c,d,e,f){var g=this;f=void 0===f?!1:f;b?(this.i=!0,Tm(b,function(){g.i=!1;var h=0<=b.indexOf("/th/");(h?window.trayride:window.botguard)?en(g,c,!!f,h,d):(Ym(b),Nk(new hi("Unable to load Botguard","from "+b)))},e)):a&&(e=Mc(document,"SCRIPT"),e.textContent=a,e.nonce=Ga(),document.head.appendChild(e),document.head.removeChild(e),((a=a.includes("trayride"))?window.trayride:window.botguard)?en(this,c,!!f,a,d):Nk(Error("Unable to load Botguard from JS")))};
function en(a,b,c,d,e){var f,g;if(d=d?null===(f=window.trayride)||void 0===f?void 0:f.ad:null===(g=window.botguard)||void 0===g?void 0:g.bg)if(c)try{fn(a,new d(b,e?function(){return e(b)}:Ka))}catch(h){h instanceof Error&&Nk(h)}else{try{fn(a,new d(b))}catch(h){h instanceof Error&&Nk(h)}e&&e(b)}else Nk(Error("Failed to finish initializing VM"))}
dn.prototype.invoke=function(a){a=void 0===a?{}:a;return this.h?this.h.hasOwnProperty("hot")?this.h.hot(void 0,void 0,a):this.h.invoke(void 0,void 0,a):null};
dn.prototype.dispose=function(){this.h=null};
function fn(a,b){a.h=b}
;var gn=new dn;function hn(){return!!gn.h}
function jn(a){a=void 0===a?{}:a;return gn.invoke(a)}
;function kn(a){L.call(this);this.i={};this.started=!1;this.connection=a;this.connection.subscribe("command",this.Da,this)}
v(kn,L);m=kn.prototype;m.start=function(){this.started||this.h||(this.started=!0,this.connection.T("RECEIVING"))};
m.T=function(a,b){this.started&&!this.h&&this.connection.T(a,b)};
m.Da=function(a,b,c){if(this.started&&!this.h){var d=b||{};switch(a){case "addEventListener":"string"===typeof d.event&&this.addListener(d.event);break;case "removeEventListener":"string"===typeof d.event&&this.removeListener(d.event);break;default:this.api.isReady()&&this.api.isExternalMethodAvailable(a,c||null)&&(b=ln(a,b||{}),c=this.api.handleExternalCall(a,b,c||null),(c=mn(a,c))&&this.T(a,c))}}};
m.addListener=function(a){if(!(a in this.i)){var b=this.fb.bind(this,a);this.i[a]=b;this.addEventListener(a,b)}};
m.fb=function(a,b){this.started&&!this.h&&this.connection.T(a,this.ka(a,b))};
m.ka=function(a,b){if(null!=b)return{value:b}};
m.removeListener=function(a){a in this.i&&(this.removeEventListener(a,this.i[a]),delete this.i[a])};
m.D=function(){var a=this.connection;a.h||We(a.i,"command",this.Da,this);this.connection=null;for(var b in this.i)this.i.hasOwnProperty(b)&&this.removeListener(b);L.prototype.D.call(this)};function nn(a,b){kn.call(this,b);this.api=a;this.start()}
v(nn,kn);nn.prototype.addEventListener=function(a,b){this.api.addEventListener(a,b)};
nn.prototype.removeEventListener=function(a,b){this.api.removeEventListener(a,b)};
function ln(a,b){switch(a){case "loadVideoById":return a=Xk(b),[a];case "cueVideoById":return a=Xk(b),[a];case "loadVideoByPlayerVars":return[b];case "cueVideoByPlayerVars":return[b];case "loadPlaylist":return a=Yk(b),[a];case "cuePlaylist":return a=Yk(b),[a];case "seekTo":return[b.seconds,b.allowSeekAhead];case "playVideoAt":return[b.index];case "setVolume":return[b.volume];case "setPlaybackQuality":return[b.suggestedQuality];case "setPlaybackRate":return[b.suggestedRate];case "setLoop":return[b.loopPlaylists];
case "setShuffle":return[b.shufflePlaylist];case "getOptions":return[b.module];case "getOption":return[b.module,b.option];case "setOption":return[b.module,b.option,b.value];case "handleGlobalKeyDown":return[b.keyCode,b.shiftKey,b.ctrlKey,b.altKey,b.metaKey,b.key,b.code]}return[]}
function mn(a,b){switch(a){case "isMuted":return{muted:b};case "getVolume":return{volume:b};case "getPlaybackRate":return{playbackRate:b};case "getAvailablePlaybackRates":return{availablePlaybackRates:b};case "getVideoLoadedFraction":return{videoLoadedFraction:b};case "getPlayerState":return{playerState:b};case "getCurrentTime":return{currentTime:b};case "getPlaybackQuality":return{playbackQuality:b};case "getAvailableQualityLevels":return{availableQualityLevels:b};case "getDuration":return{duration:b};
case "getVideoUrl":return{videoUrl:b};case "getVideoEmbedCode":return{videoEmbedCode:b};case "getPlaylist":return{playlist:b};case "getPlaylistIndex":return{playlistIndex:b};case "getOptions":return{options:b};case "getOption":return{option:b}}}
nn.prototype.ka=function(a,b){switch(a){case "onReady":return;case "onStateChange":return{playerState:b};case "onPlaybackQualityChange":return{playbackQuality:b};case "onPlaybackRateChange":return{playbackRate:b};case "onError":return{errorCode:b}}return kn.prototype.ka.call(this,a,b)};
nn.prototype.D=function(){kn.prototype.D.call(this);delete this.api};function on(a){a=void 0===a?!1:a;L.call(this);this.i=new M(a);Hd(this,Ua(Fd,this.i))}
C(on,L);on.prototype.subscribe=function(a,b,c){return this.h?0:this.i.subscribe(a,b,c)};
on.prototype.l=function(a,b){this.h||this.i.S.apply(this.i,arguments)};function pn(a,b,c){on.call(this);this.j=a;this.destination=b;this.id=c}
v(pn,on);pn.prototype.T=function(a,b){this.h||this.j.T(this.destination,this.id,a,b)};
pn.prototype.D=function(){this.destination=this.j=null;on.prototype.D.call(this)};function qn(a,b,c){L.call(this);this.destination=a;this.origin=c;this.i=Gf(window,"message",this.j.bind(this));this.connection=new pn(this,a,b);Hd(this,Ua(Fd,this.connection))}
v(qn,L);qn.prototype.T=function(a,b,c,d){this.h||a!==this.destination||(a={id:b,command:c},d&&(a.data=d),this.destination.postMessage(xe(a),this.origin))};
qn.prototype.j=function(a){var b;if(b=!this.h)if(b=a.origin===this.origin)a:{b=this.destination;do{b:{var c=a.source;do{if(c===b){c=!0;break b}if(c===c.parent)break;c=c.parent}while(null!=c);c=!1}if(c){b=!0;break a}b=b.opener}while(null!=b);b=!1}if(b&&(b=a.data,"string"===typeof b)){try{b=JSON.parse(b)}catch(d){return}b.command&&(c=this.connection,c.h||c.l("command",b.command,b.data,a.origin))}};
qn.prototype.D=function(){Hf(this.i);this.destination=null;L.prototype.D.call(this)};function rn(){L.call(this);this.i=[]}
v(rn,L);rn.prototype.D=function(){for(;this.i.length;){var a=this.i.pop();a.target.removeEventListener(a.name,a.Ia)}L.prototype.D.call(this)};function sn(a){a=a||{};var b={},c={};this.url=a.url||"";this.args=a.args||pb(b);this.assets=a.assets||{};this.attrs=a.attrs||pb(c);this.fallback=a.fallback||null;this.fallbackMessage=a.fallbackMessage||null;this.html5=!!a.html5;this.disable=a.disable||{};this.loaded=!!a.loaded;this.messages=a.messages||{}}
sn.prototype.clone=function(){var a=new sn,b;for(b in this)if(this.hasOwnProperty(b)){var c=this[b];"object"==Ma(c)?a[b]=pb(c):a[b]=c}return a};var tn=/cssbin\/(?:debug-)?([a-zA-Z0-9_-]+?)(?:-2x|-web|-rtl|-vfl|.css)/;function un(a){a=a||"";if(window.spf){var b=a.match(tn);spf.style.load(a,b?b[1]:"",void 0)}else vn(a)}
function vn(a){var b=wn(a),c=document.getElementById(b),d=c&&Pm(c,"loaded");d||c&&!d||(c=xn(a,b,function(){Pm(c,"loaded")||(Nm(c),Rg(b),Jf(Ua(Sg,b),0))}))}
function xn(a,b,c){var d=document.createElement("link");d.id=b;d.onload=function(){c&&setTimeout(c,0)};
a=Uc(a);Wb(d,a);(document.getElementsByTagName("head")[0]||document.body).appendChild(d);return d}
function wn(a){var b=Mc(document,"A");Vb(b,new Hb(a,Ib));a=b.href.replace(/^[a-zA-Z]+:\/\//,"//");return"css-"+bc(a)}
;function yn(a,b,c,d){L.call(this);var e=this;this.F=b;this.webPlayerContextConfig=d;this.ha=!1;this.api={};this.V=this.m=null;this.J=new M;this.i={};this.L=this.aa=this.elementId=this.ia=this.config=null;this.K=!1;this.l=this.B=null;this.ba={};this.Ga=["onReady"];this.lastError=null;this.sa=NaN;this.C={};this.Ha=new rn(this);this.N=0;this.j=this.o=a;Hd(this,Ua(Fd,this.J));zn(this);An(this);Hd(this,Ua(Fd,this.Ha));c?this.N=Jf(function(){e.loadNewVideoConfig(c)},0):d&&(Bn(this),Cn(this))}
v(yn,L);m=yn.prototype;m.getId=function(){return this.F};
m.loadNewVideoConfig=function(a){if(!this.h){this.N&&(Kf(this.N),this.N=0);var b=a||{};b instanceof sn||(b=new sn(b));this.config=b;this.setConfig(a);Cn(this);this.isReady()&&Dn(this)}};
function Bn(a){var b,c;a.webPlayerContextConfig?c=a.webPlayerContextConfig.rootElementId:c=a.config.attrs.id;a.elementId=c||a.elementId;"video-player"===a.elementId&&(a.elementId=a.F,a.webPlayerContextConfig?a.webPlayerContextConfig.rootElementId=a.F:a.config.attrs.id=a.F);(null===(b=a.j)||void 0===b?void 0:b.id)===a.elementId&&(a.elementId+="-player",a.webPlayerContextConfig?a.webPlayerContextConfig.rootElementId=a.elementId:a.config.attrs.id=a.elementId)}
m.setConfig=function(a){var b;this.ia=a;this.config=En(a);Bn(this);this.aa||(this.aa=Fn(this,(null===(b=this.config.args)||void 0===b?void 0:b.jsapicallback)||"onYouTubePlayerReady"));this.config.args?this.config.args.jsapicallback=null:this.config.args={jsapicallback:null};var c;if(null===(c=this.config)||void 0===c?0:c.attrs)a=this.config.attrs,(c=a.width)&&this.j&&(this.j.style.width=Wc(Number(c)||c)),(a=a.height)&&this.j&&(this.j.style.height=Wc(Number(a)||a))};
function Dn(a){var b;a.config&&!0!==a.config.loaded&&(a.config.loaded=!0,!a.config.args||"0"!==a.config.args.autoplay&&0!==a.config.args.autoplay&&!1!==a.config.args.autoplay?a.api.loadVideoByPlayerVars(null!==(b=a.config.args)&&void 0!==b?b:null):a.api.cueVideoByPlayerVars(a.config.args))}
function Gn(a){var b=!0,c=Hn(a);c&&a.config&&(a=In(a),b=Pm(c,"version")===a);return b&&!!A("yt.player.Application.create")}
function Cn(a){if(!a.h&&!a.K){var b=Gn(a);if(b&&"html5"===(Hn(a)?"html5":null))a.L="html5",a.isReady()||Jn(a);else if(Kn(a),a.L="html5",b&&a.l&&a.o)a.o.appendChild(a.l),Jn(a);else{a.config&&(a.config.loaded=!0);var c=!1;a.B=function(){c=!0;var d=Ln(a,"player_bootstrap_method")?A("yt.player.Application.createAlternate")||A("yt.player.Application.create"):A("yt.player.Application.create");var e=a.config?En(a.config):void 0;d&&d(a.o,e,a.webPlayerContextConfig);Jn(a)};
a.K=!0;b?a.B():(Tm(In(a),a.B),(b=Mn(a))&&un(b),Nn(a)&&!c&&z("yt.player.Application.create",null,void 0))}}}
function Hn(a){var b=Ic(a.elementId);!b&&a.j&&a.j.querySelector&&(b=a.j.querySelector("#"+a.elementId));return b}
function Jn(a){var b;if(!a.h){var c=Hn(a),d=!1;c&&c.getApiInterface&&c.getApiInterface()&&(d=!0);d?(a.K=!1,!Ln(a,"html5_remove_not_servable_check_killswitch")&&(null===c||void 0===c?0:c.isNotServable)&&a.config&&(null===c||void 0===c?0:c.isNotServable(null===(b=a.config.args)||void 0===b?void 0:b.video_id))||On(a)):a.sa=Jf(function(){Jn(a)},50)}}
function On(a){zn(a);a.ha=!0;var b=Hn(a);if(b){a.m=Pn(a,b,"addEventListener");a.V=Pn(a,b,"removeEventListener");var c=b.getApiInterface();c=c.concat(b.getInternalApiInterface());for(var d=a.api,e=0;e<c.length;e++){var f=c[e];d[f]||(d[f]=Pn(a,b,f))}}for(var g in a.i)a.i.hasOwnProperty(g)&&a.m&&a.m(g,a.i[g]);Dn(a);a.aa&&a.aa(a.api);a.J.S("onReady",a.api)}
function Pn(a,b,c){var d=b[c];return function(e){for(var f=[],g=0;g<arguments.length;++g)f[g-0]=arguments[g];try{return a.lastError=null,d.apply(b,f)}catch(h){"sendAbandonmentPing"!==c&&(h.params=c,a.lastError=h,Nk(h))}}}
function zn(a){a.ha=!1;if(a.V)for(var b in a.i)a.i.hasOwnProperty(b)&&a.V(b,a.i[b]);for(var c in a.C)a.C.hasOwnProperty(c)&&Kf(Number(c));a.C={};a.m=null;a.V=null;b=a.api;for(var d in b)b.hasOwnProperty(d)&&(b[d]=null);b.addEventListener=function(e,f){a.addEventListener(e,f)};
b.removeEventListener=function(e,f){a.removeEventListener(e,f)};
b.destroy=function(){a.dispose()};
b.getLastError=function(){return a.getLastError()};
b.getPlayerType=function(){return a.getPlayerType()};
b.getCurrentVideoConfig=function(){return a.ia};
b.loadNewVideoConfig=function(e){a.loadNewVideoConfig(e)};
b.isReady=function(){return a.isReady()}}
m.isReady=function(){return this.ha};
function An(a){a.addEventListener("WATCH_LATER_VIDEO_ADDED",function(b){Rg("WATCH_LATER_VIDEO_ADDED",b)});
a.addEventListener("WATCH_LATER_VIDEO_REMOVED",function(b){Rg("WATCH_LATER_VIDEO_REMOVED",b)});
a.addEventListener("onAdAnnounce",function(b){Rg("a11y-announce",b)})}
m.addEventListener=function(a,b){var c=this,d=Fn(this,b);d&&(0<=$a(this.Ga,a)||this.i[a]||(b=Qn(this,a),this.m&&this.m(a,b)),this.J.subscribe(a,d),"onReady"===a&&this.isReady()&&Jf(function(){d(c.api)},0))};
m.removeEventListener=function(a,b){this.h||(b=Fn(this,b))&&We(this.J,a,b)};
function Fn(a,b){var c=b;if("string"===typeof b){if(a.ba[b])return a.ba[b];c=function(d){for(var e=[],f=0;f<arguments.length;++f)e[f-0]=arguments[f];(f=A(b))&&f.apply(y,e)};
a.ba[b]=c}return c?c:null}
function Qn(a,b){var c="ytPlayer"+b+a.F;a.i[b]=c;y[c]=function(d){var e=Jf(function(){if(!a.h){a.J.S(b,d);var f=a.C,g=String(e);g in f&&delete f[g]}},0);
lb(a.C,String(e))};
return c}
m.getPlayerType=function(){return this.L||(Hn(this)?"html5":null)};
m.getLastError=function(){return this.lastError};
function Kn(a){a.cancel();zn(a);a.L=null;a.config&&(a.config.loaded=!1);var b=Hn(a);b&&(Gn(a)||!Nn(a)?a.l=b:(b&&b.destroy&&b.destroy(),a.l=null));if(a.o)for(a=a.o;b=a.firstChild;)a.removeChild(b)}
m.cancel=function(){this.B&&Zm(In(this),this.B);Kf(this.sa);this.K=!1};
m.D=function(){Kn(this);if(this.l&&this.config&&this.l.destroy)try{this.l.destroy()}catch(b){Ok(b)}this.ba=null;for(var a in this.i)this.i.hasOwnProperty(a)&&(y[this.i[a]]=null);this.ia=this.config=this.api=null;delete this.o;delete this.j;L.prototype.D.call(this)};
function Nn(a){var b,c;a=null===(c=null===(b=a.config)||void 0===b?void 0:b.args)||void 0===c?void 0:c.fflags;return!!a&&-1!==a.indexOf("player_destroy_old_version=true")}
function In(a){return a.webPlayerContextConfig?a.webPlayerContextConfig.jsUrl:(a=a.config.assets)?a.js:""}
function Mn(a){return a.webPlayerContextConfig?a.webPlayerContextConfig.cssUrl:(a=a.config.assets)?a.css:""}
function Ln(a,b){var c;if(a.webPlayerContextConfig)var d=a.webPlayerContextConfig.serializedExperimentFlags;else if(null===(c=a.config)||void 0===c?0:c.args)d=a.config.args.fflags;return"true"===cg(d||"","&")[b]}
function En(a){for(var b={},c=u(Object.keys(a)),d=c.next();!d.done;d=c.next()){d=d.value;var e=a[d];b[d]="object"===typeof e?pb(e):e}return b}
;var Rn={},Sn="player_uid_"+(1E9*Math.random()>>>0);function Tn(a,b,c){var d="player";c=void 0===c?!0:c;d="string"===typeof d?Ic(d):d;var e=Sn+"_"+Pa(d),f=Rn[e];if(f&&c)return Un(a,b)?f.api.loadVideoByPlayerVars(a.args||null):f.loadNewVideoConfig(a),f.api;f=new yn(d,e,a,b);Rn[e]=f;Rg("player-added",f.api);Hd(f,function(){delete Rn[f.getId()]});
return f.api}
function Un(a,b){return b&&b.serializedExperimentFlags?b.serializedExperimentFlags.includes("web_player_remove_playerproxy=true"):a&&a.args&&a.args.fflags?a.args.fflags.includes("web_player_remove_playerproxy=true"):!1}
;var Vn=null,Wn=null,Xn=null;function Yn(){var a=Vn.getVideoData(1);a=a.title?a.title+" - YouTube":"YouTube";document.title!==a&&(document.title=a)}
;function Zn(a,b,c){a="ST-"+bc(a).toString(36);b=b?gc(b):"";c=c||5;var d=ed.get("CONSENT",void 0);d&&!d.startsWith("YES+")||th(a,b,c)}
;function $n(a,b,c){b=void 0===b?{}:b;c=void 0===c?!1:c;var d=F("EVENT_ID");d&&(b.ei||(b.ei=d));if(b){d=a;var e=void 0===e?!0:e;var f=F("VALID_SESSION_TEMPDATA_DOMAINS",[]),g=ec(window.location.href);g&&f.push(g);g=ec(d);if(0<=$a(f,g)||!g&&0==d.lastIndexOf("/",0))if(Q("autoescape_tempdata_url")&&(f=document.createElement("a"),Vb(f,d),d=f.href),d){g=d.match(cc);d=g[5];f=g[6];g=g[7];var h="";d&&(h+=d);f&&(h+="?"+f);g&&(h+="#"+g);d=h;f=d.indexOf("#");if(d=0>f?d:d.substr(0,f))if(e&&!b.csn&&(b.itct||b.ved)&&
(b=Object.assign({csn:Al()},b)),k){var k=parseInt(k,10);isFinite(k)&&0<k&&Zn(d,b,k)}else Zn(d,b)}}if(c)return!1;if((window.ytspf||{}).enabled)spf.navigate(a);else{var l=void 0===l?{}:l;var p=void 0===p?"":p;var n=void 0===n?window:n;c=n.location;a=hc(a,l)+p;a=a instanceof Hb?a:Nb(a);c.href=Jb(a)}return!0}
;z("yt.setConfig",N,void 0);z("yt.config.set",N,void 0);z("yt.setMsg",vf,void 0);z("yt.msgs.set",vf,void 0);z("yt.logging.errors.log",Ok,void 0);
z("writeEmbed",function(){var a=F("PLAYER_CONFIG",void 0);if(!a){var b=F("PLAYER_VARS",void 0);b&&(a={args:b})}nl(!0);"gvn"===a.args.ps&&(document.body.style.backgroundColor="transparent");a.attrs||(a.attrs={width:"100%",height:"100%",id:"video-player"});var c=document.referrer;b=F("POST_MESSAGE_ORIGIN");window!==window.top&&c&&c!==document.URL&&(a.args.loaderUrl=c);F("EXPERIMENT_FLAGS").embeds_js_api_set_1p_cookie&&(c=hg(),c.embedsTokenValue&&(a.args.embedsTokenValue=c.embedsTokenValue));F("EXPERIMENT_FLAGS").embeds_web_force_csi_on_gel&&
N("FORCE_CSI_ON_GEL",!0);c=["ol"];jm("").info.actionType="embed";c&&N("TIMING_AFT_KEYS",c);N("TIMING_ACTION","embed");c=F("TIMING_INFO",{});for(var d in c)c.hasOwnProperty(d)&&zm(d,c[d]);zm("is_nav",1);(d=Al())&&zm("csn",d);(d=F("PREVIOUS_ACTION",void 0))&&!um()&&zm("pa",d);d=em();c=F("CLIENT_PROTOCOL");var e=F("CLIENT_TRANSPORT");c&&zm("p",c);e&&zm("t",e);zm("yt_vis",Em());zm("yt_lt","cold");c=am();if(e=cm())Z("srt",c.responseStart),1!==d.prerender&&(zm("yt_sts","n",void 0),Z("_start",e,void 0));
d=hm();0<d&&Z("fpt",d);if(!Q("log_deltas_killswitch")){var f,g,h,k;W&&W.timing&&(W.timeOrigin&&W.timing.navigationStart&&Bm("startTimeDelta",Math.floor(W.timeOrigin)-W.timing.navigationStart),(d=null===(k=null===(h=null===(g=null===(f=W.getEntriesByType)||void 0===f?void 0:f.call(W,"navigation"))||void 0===g?void 0:g[0])||void 0===h?void 0:h.toJSON)||void 0===k?void 0:k.call(h))&&d.responseEnd&&W.timing.responseEnd&&Bm("responseEndDelta",bm(d.responseEnd)-W.timing.responseEnd))}f=am();f.isPerformanceNavigationTiming&&
zm("pnt",1,void 0);Z("nreqs",f.requestStart,void 0);Z("nress",f.responseStart,void 0);Z("nrese",f.responseEnd,void 0);0<f.redirectEnd-f.redirectStart&&(Z("nrs",f.redirectStart,void 0),Z("nre",f.redirectEnd,void 0));0<f.domainLookupEnd-f.domainLookupStart&&(Z("ndnss",f.domainLookupStart,void 0),Z("ndnse",f.domainLookupEnd,void 0));0<f.connectEnd-f.connectStart&&(Z("ntcps",f.connectStart,void 0),Z("ntcpe",f.connectEnd,void 0));f.secureConnectionStart>=cm()&&0<f.connectEnd-f.secureConnectionStart&&(Z("nstcps",
f.secureConnectionStart,void 0),Z("ntcpe",f.connectEnd,void 0));W&&W.getEntriesByType&&Gm();f=[];if(document.querySelector&&W&&W.getEntriesByName)for(var l in Yl)Yl.hasOwnProperty(l)&&(g=Yl[l],Fm(l,g)&&f.push(g));f.length&&zm("rc",f.join(","));if(um(void 0)){l={actionType:om[F("TIMING_ACTION",void 0)]||"LATENCY_ACTION_UNKNOWN",previousAction:om[F("PREVIOUS_ACTION",void 0)]||"LATENCY_ACTION_UNKNOWN"};if(f=Al())l.clientScreenNonce=f;f=fm(void 0);mm().info(l,f)}l=em();g=$l();if("cold"===l.yt_lt&&(f=
wm(),h=f.gelTicks?f.gelTicks:f.gelTicks={},f=f.gelInfos?f.gelInfos:f.gelInfos={},um())){for(var p in g)"tick_"+p in h||vm(p,g[p]);p=ym();g=fm();h={};for(var n in l)"info_"+n in f||!(k=xm(n,l[n]))||(Ml(p,k),Ml(h,k));mm().info(h,g)}z("ytglobal.timingready_",!0,void 0);Am();(n=F("WEB_PLAYER_CONTEXT_CONFIGS",void 0))&&"WEB_PLAYER_CONTEXT_CONFIG_ID_EMBEDDED_PLAYER"in n?(n=n.WEB_PLAYER_CONTEXT_CONFIG_ID_EMBEDDED_PLAYER,n.serializedForcedExperimentIds||(p=hg(),p.forced_experiments&&(n.serializedForcedExperimentIds=
p.forced_experiments)),Vn=Tn(a,n,!1)):Vn=Tn(a);Vn.addEventListener("onVideoDataChange",Yn);a=F("POST_MESSAGE_ID","player");F("ENABLE_JS_API")?Xn=new Zk(Vn):F("ENABLE_POST_API")&&"string"===typeof a&&"string"===typeof b&&(Wn=new qn(window.parent,a,b),Xn=new nn(Vn,Wn.connection));bn();F("EXPERIMENT_FLAGS").networkless_logging_web_embedded&&kk()},void 0);
var ao=rf(function(){Cm();var a=vh.getInstance(),b=!!((yh("f"+(Math.floor(119/31)+1))||0)&67108864),c=1<window.devicePixelRatio;if(document.body&&Kd(document.body,"exp-invert-logo"))if(c&&!Kd(document.body,"inverted-hdpi")){var d=document.body;if(d.classList)d.classList.add("inverted-hdpi");else if(!Kd(d,"inverted-hdpi")){var e=Id(d);Jd(d,e+(0<e.length?" inverted-hdpi":"inverted-hdpi"))}}else!c&&Kd(document.body,"inverted-hdpi")&&Ld();if(b!=c){b="f"+(Math.floor(119/31)+1);d=yh(b)||0;d=c?d|67108864:
d&-67108865;0==d?delete uh[b]:(c=d.toString(16),uh[b]=c.toString());c=!0;Q("web_secure_pref_cookie_killswitch")&&(c=!1);b=a.h;d=[];for(var f in uh)d.push(f+"="+encodeURIComponent(String(uh[f])));th(b,d.join("&"),63072E3,a.i,c)}Im.h||(Im.h=new Im);a=Im.h;f=16623;var g=void 0===g?{}:g;Object.values(Qk).includes(f)||(Nk(new hi("createClientScreen() called with a non-page VE",f)),f=83769);g.isHistoryNavigation||a.h.push({rootVe:f,key:g.key||""});a.l=[];a.u=[];g.wa?Lm(a,f,g):Mm(a,f,g)}),bo=rf(function(){Vn&&
Vn.sendAbandonmentPing&&Vn.sendAbandonmentPing();
F("PL_ATT")&&gn.dispose();for(var a=0,b=$m.length;a<b;a++)Sf($m[a]);$m.length=0;Ym("//static.doubleclick.net/instream/ad_status.js");an=!1;N("DCLKSTAT",0);Gd(Xn,Wn);Vn&&(Vn.removeEventListener("onVideoDataChange",Yn),Vn.destroy())});
window.addEventListener?(window.addEventListener("load",ao),window.addEventListener("unload",bo)):window.attachEvent&&(window.attachEvent("onload",ao),window.attachEvent("onunload",bo));Va("yt.abuse.player.botguardInitialized",A("yt.abuse.player.botguardInitialized")||hn);Va("yt.abuse.player.invokeBotguard",A("yt.abuse.player.invokeBotguard")||jn);Va("yt.abuse.dclkstatus.checkDclkStatus",A("yt.abuse.dclkstatus.checkDclkStatus")||cn);
Va("yt.player.exports.navigate",A("yt.player.exports.navigate")||$n);Va("yt.util.activity.init",A("yt.util.activity.init")||Uf);Va("yt.util.activity.getTimeSinceActive",A("yt.util.activity.getTimeSinceActive")||Xf);Va("yt.util.activity.setTimestamp",A("yt.util.activity.setTimestamp")||Vf);}).call(this);
