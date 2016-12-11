import qualified Data.List as L

-- F# replacements.

bucketSortBy = L.sortBy -- fix later

permute :: (Int -> Int) -> [a] -> [a]
permute f xs = L.map snd
               $ bucketSortBy (\(i, _) (j, _) -> compare i j)
               $ zipWith (\i x -> (f i, x)) [0..] xs

nth :: [a] -> Int -> a
nth = (L.!!)

fold = L.foldl


-- Code

sort :: Ord a => [a] -> [a]
sort xs = permute (nthSmallest xs . nth xs) xs

nthSmallest :: Ord a => [a] -> a -> Int
nthSmallest xs x = fold (\level y -> if x > y
                                     then level + 1
                                     else level) 0 xs
