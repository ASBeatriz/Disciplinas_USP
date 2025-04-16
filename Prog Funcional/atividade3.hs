-- Atividade 3:
-- leia dois inteiros x e y, sendo que x é menor que y, e imprima o comprimento do maior 
-- intervalo entre dois números primos consecutivos maiores ou iguais a x e menores ou iguais a y.

main = do
    la <- getLine
    let a = read la
    lb <- getLine
    let b = read lb

    let lista  =  pegaEqto (<= b) $ ignoraEqto (< a) primos
    putStrLn $ show $ maior $ zipa lista

-- Lista dos números primos 
primos = crivo [2..]
    where   
        crivo (x:xs) = x: (crivo $ filtra ((/= 0).(`mod` x)) xs)

-- Função que ignora os elementos de uma lista enquanto eles satisfazem uma condição
ignoraEqto :: (a->Bool) -> [a] -> [a]
ignoraEqto _ [] = []
ignoraEqto teste (x:xs) 
    | teste x = ignoraEqto teste xs
    | otherwise = x:xs

-- Função que pega os elementos de uma lista enquanto eles satisfazem uma condição
pegaEqto :: (a->Bool) -> [a] -> [a]
pegaEqto _ [] = []
pegaEqto teste (x:xs) 
    | teste x = x:pegaEqto teste xs
    | otherwise = []

-- Função que filtra uma lista de acordo com uma condição
filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra f (x:xs)
    | f x = x: filtra f xs
    | otherwise = filtra f xs

-- Função para gerar um lista com as diferenças entre dois números consecutivos de outra lista
zipa :: (Num a, Eq a) => [a] -> [a]
zipa [] = []
zipa (x:xs)
    | xs == [] = []
    | otherwise = ((head xs) - x): zipa xs

-- Quicks-sort, ordena os elementos de forma decrescente
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (pivot:xs) = maiores ++ iguais ++ menores
    where
        menores = quicksort $ filtra (< pivot) xs
        maiores = quicksort $ filtra (> pivot) xs
        iguais = pivot:filtra (== pivot) xs

-- Função que retorna o maior número de uma lista
maior :: (Ord a, Num a) => [a] -> a
maior [] = 0
maior (x:xs) = head $ quicksort (x:xs)