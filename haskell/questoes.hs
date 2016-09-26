--comments
{-
 - comments
-}
import Data.List
{-
doubleMe x = x + x

doubleUs x y = doubleMe x + doubleMe y

doubleSmallNumber x = if x > 100
						then x
						else x*2
{-
numbers = [1, 2, 3] ++ [4, 5, 6] -- [1, 2, 3, 4, 5, 6]
5:[1, 2] -- [5, 1, 2]

[1, 2, 3] !! 1 -- 2

head [5, 4, 3] -- 5
tail [5, 4, 3] -- [4, 3]
last [5, 4, 3] -- 3
init [5, 4, 3] -- [5, 4]
-}
boomBangs xs = [if x < 10 then "boom!" else "bang!" | x <- xs, odd x]
-}


--fatorial 1
factorial :: Int -> Int
factorial 0 = 1
factorial n = factorial(n-1)*n

--fibonacci 2
fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci(n-1) + fibonacci(n-2)

fibonacci' :: Int -> [Int]
fibonacci' list = [fibonacci x | x <- [0..list]]

--interseccao 4
interseccao :: [Int] -> [Int] -> [Int]
interseccao a b = [x | x <- a, x `elem` b]

-- 5
rodaEsq :: [Int] -> [Int]
rodaEsq (x:xs) = xs ++ [x]

--seleciona 7
seleciona :: [Char] -> [Int] -> [Char]
seleciona a b = [a !! (x-1) | x <- b]

--primo 8
list :: Int -> [Int]
list n = [2..(n-1)]

primo :: Int -> [Int] -> Bool
primo p[] = True
primo p (x:res) = if (p `mod` x) == 0
					then False
					else primo p res

primo' :: Int -> Bool
primo' p = primo p (list p)
