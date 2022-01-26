// A scratch file for just messing arounf with JS code

// let map = new Map().set('a', 1).set('b', 2)
let map = new Map()

map.set('the',23)
map.set("a", 2)

// map["the"] = 17;
// map["hi"] = 11
let array = Array.from(map, ([word, count]) => ({ word, count }));

console.log(array);