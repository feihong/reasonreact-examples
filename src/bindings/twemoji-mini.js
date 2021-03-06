// Extracted from:
// https://github.com/twitter/twemoji/blob/gh-pages/2/twemoji.js

function toCodePoint(unicodeSurrogates, sep) {
  var r = [],
    c = 0,
    p = 0,
    i = 0;
  while (i < unicodeSurrogates.length) {
    c = unicodeSurrogates.charCodeAt(i++);
    if (p) {
      r.push((0x10000 + ((p - 0xd800) << 10) + (c - 0xdc00)).toString(16));
      p = 0;
    } else if (0xd800 <= c && c <= 0xdbff) {
      p = c;
    } else {
      r.push(c.toString(16));
    }
  }
  return r.join(sep || "-");
}

const U200D = String.fromCharCode(0x200d);
const UFE0Fg = /\uFE0F/g;

// Given an emoji character, return the corresponding code point
function grabTheRightIcon(rawText) {
  // if variant is present as \uFE0F
  return toCodePoint(
    rawText.indexOf(U200D) < 0 ? rawText.replace(UFE0Fg, "") : rawText
  );
}

module.exports = { grabTheRightIcon };
