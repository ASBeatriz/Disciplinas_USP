main = do
    putStrLn $ "oi"
    putStrLn $ show $ funcao123 5 4
    putStrLn $ show $ 5 +==+ 4
    putStrLn $ show $ a
    putStrLn $ show $ b
    putStrLn $ show $ c
    putStrLn $ show $ f 10
    putStrLn $ show $ g 10
    putStrLn $ show $ h 10
    putStrLn $ show $ mapa dobro lista
    putStrLn $ show $ filtra ehPar lista    
    putStrLn $ show $ 2 `pertence` lista
    putStrLn $ show $ 3 `pertence` lista
    putStrLn $ show $ add 2 3 
    putStrLn $ show $ add 5.8 2.4   -- agora é possível usar com outros números sem ser apenas inteiro 
    putStrLn $ show $ somaElem $ mapa (^2) $ filtra (<5) lista  -- soma dos quadrados dos elementos menores do que cinco
    putStrLn $ show $ somaElem $ mapa (^2) $ pega 3 $ filtra (<5) lista  -- soma dos quadrados dos três primeiros elementos menores do que cinco
    -- Outra forma de escrever para facilitar a leitura (de baixo para cima)
    putStrLn $ 
        show $ 
        somaElem $ 
        mapa (^2) $ 
        pega 3 $ 
        filtra (<5) lista 


    putStrLn $ show $ ["a", "b", "c", "d"] ++ ["E", "F", "G"]   -- concatenação de listas

    putStrLn $ show $ lista
    putStrLn $ show $ quickSort lista


-- funcao123 e +==+ são identificadores (função), assim como o +, -, etc.
funcao123 x y = x*y     -- identificadores que são letras seguidas de números são prefixo  (antes dos parametros)
x +==+ y = x*y          -- identificadores que são caracteres desse tipo são infixo (entre os parametros)

-- É possível usar infixo como prefixo e vice-versa
a = 2 `funcao123` 3     -- usar `` para usar como infixo
b = (+==+) 2 3          -- usar () para usar como prefixo
    -- exemplo de legibilidade:
c = 4 `mod` 2          -- o normal seria mod 4 2

-- função soma
soma x y = x + y

-- essas funções são identicas
f x = soma 5 x
g = soma 5

-- usando o + como prefixo:
soma' x y = (+) x y
f' x = (+) 5 x
g' = (+) 5
h = (+5)   -- mais legível / facil de entender

-- mapear (transformar) elementos de uma lista
mapa :: (a -> b) -> [a] -> [b]
mapa _ [] = []
mapa f (x:xs) = f x:mapa f xs   -- transforma a cabeça e repete o processo na lista restante e concatena o resultado ateee acabar

dobro x = 2*x   -- exemplo de função
lista = [1, 3, 0, 4, 5, 7, 10, 2]     -- exemplo de lista

-- filtrar elementos de uma lista
filtra :: (a -> Bool) -> [a] -> [a]
filtra teste [] = []
filtra teste (x:xs)
    | teste x = x:filtra teste xs   -- se passar no teste, eu adiciono na lista,
    | otherwise = filtra teste xs   -- senão, eu continuo procurando

ehPar x = x `mod` 2 == 0    -- exemplo de teste

-- Classes de tipo
-- É uma forma de classificar os tipos de acordo com suas características, por exemplo: ser comparado (==), ser ordenado (<, >)...

-- "Eq" é a classe de tipos que podem ser comparados em igualdade (==)
pertence :: (Eq a) => a -> [a] -> Bool
_ `pertence` [] = False
a `pertence` (x:xs)
    | a == x = True
    | otherwise = a `pertence` xs

-- Generalizar a função de soma com a classe de tipo Num
-- add :: Integer -> Integer -> Integer
add :: (Num a) => a -> a -> a
add x y = x + y

somaElem :: (Num a) => [a] -> a
somaElem [] = 0
somaElem (x:xs) = x + somaElem xs

-- Função que pega retorna os primeiros n elementos de uma lista
pega :: Integer -> [a] -> [a]
pega 0 _ = []
pega _ [] = []
pega n (x:xs) = x: pega (n-1) xs

-- Implementação do quick sort
-- classe de tipo Ord para elementos ordenáveis
quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (pivot:xs) = menores ++ iguais ++ maiores
    where
        menores = quickSort $ filtra (< pivot) xs
        iguais = pivot: filtra (== pivot) xs
        maiores = quickSort $ filtra (> pivot) xs
