# goods-comparer #

It's a simple tool that, given technical characteristics of some goods, can choose the best.

## Input format ##

In the project repo you should put a file `data.txt`, that will contain technical characteristics of the analyzed goods. In the first string of the input two positive integer should be put, splitted by a space --- these are a total number of goods and a number (let's call it `n`) of characteristics of each good (let's call it `m`).

On the next `n` strings you should write `m` characteristics for each good. Each characteristic is presented by an integer. Characteristics should be splitted by a space. **goods-comparer** will think, that the bigger value has an integer, the better is the characteristic.

## How the best good is chosen ##

**goods-comparer** tries to find the best good by holding competitions between the goods. `m` competitions are hold; for each characteristic the goods are sorted in an ascending order, so every good gets a place in this competition. Then these places are being summed for every good; the good that has the smallest sum is admitted to be the best good.