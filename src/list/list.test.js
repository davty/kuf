const kuf = require('bindings')('kuf');

describe('', () => {
  test('can create an empty list', () => {
    expect(kuf.List().length).toBe(0);
  });

  test('can create single-element list', () => {
    console.log(kuf.List(1, 2, 3).debug);
    console.log(kuf.List(1).debug);
    expect(kuf.List(1).length).toBe(1);
  });
});