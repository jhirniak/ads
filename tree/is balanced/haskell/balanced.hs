-- by Jakub Zalewski
-- 12 November 2014

data Tree a = Branch (Tree a) a (Tree a)
            | Tip

balanced :: Tree a -> Bool
balanced a = (depthMax a) - (depthMin a) <= 1
  where
    depth :: (Int -> Int -> Int) -> Tree a -> Int
    depth _ Tip = 0
    depth fun (Branch left _ right) = fun (depth fun left) (depth fun right) + 1
    depthMin = depth min
    depthMax = depth max

balancedTree = Branch (Branch (Branch Tip 3 Tip) 1 (Branch Tip 4 Tip)) 0 (Branch (Branch Tip 5 Tip) 2 (Branch Tip 6 Tip))
unbalancedTree = Branch (Branch (Branch Tip 3 Tip) 2 Tip) 1 Tip


