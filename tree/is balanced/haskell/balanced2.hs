{-# LANGUAGE Trustworthy, NamedFieldPuns  #-}
-- by Jakub Zalewski
-- 13 November 2014

-- Using Data.Tree, for arbitrary trees
import Data.Tree

balancedTree, unbalancedTree :: Tree Int
balancedTree = Node 0 [Node 1 [return 3, return 4] , Node 2 [return 5, return 6]]
unbalancedTree = Node 1 [Node 2 [return 3]]

-- calculate depth of the tree in a standard way
depth :: (Int -> Int -> Int) -> Tree a -> Int
depth f (Node {subForest=children}) = 1 + reduce depths
  where
    reduce :: [Int] -> Int
    reduce [] = 0
    reduce [a] = a
    reduce (a:rest) = foldr f a rest
    depths :: [Int]
    depths = fmap (depth f) children

balanced :: Tree a -> Bool
balanced t = depth max t - depth min t <= 1

-- for now just print the tree
main :: IO ()
main = mapM_ (print . balanced) [balancedTree, unbalancedTree]

