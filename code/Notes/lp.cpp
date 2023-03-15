Primal <-> Dual

Seja o primal definido por:

1) max{ sum[1<=i<=N]:{ X(i) * B(i) }}
		B(i) pertence a um set B fixo.
		X(i) pertence a um set X -> variaveis

2) constraints, assumindo que existem M constraints:
		a) tipo ">=": sum[1<=i<=N]:{ A(j, i) * X(i) } >= C(j)
		b) tipo "<=": sum[1<=i<=N]:{ A(j, i) * X(i) } <= C(j)
		c) tipo "=":  sum[1<=i<=N]:{ A(j, i) * X(i) } = C(j)

		j: j-th constraint
		A: matrix que representa os valores de todas as constraints
		A(j, i): i-esimo valor da constraint j.
		C: resultado da inequacao/equacao da constraint

3) variaveis podendo ser:
		a) X(i) >= 0
		b) X(i) <= 0
		C) X(i) livre

a transformacao pro dual, eh dado por:

1) min{ sum[1<=j<=M]:{ Y(j) * C(j) }}
		Y(j) eh o novo conjunto de variaveis

2) novos dominios das variaveis:
		a) se o tipo da j-th constraint no primal eh ">=", entao Y(j) <= 0.
		b) se o tipo da j-th constraint no primal eh "<=", entao Y(j) >= 0.
		c) se o tipo da j-th constraint no primal eh "=", entao Y(j) eh livre.

3) novos constraints, N agora:
		a) se X(i) >= 0 no primal, entao:
				sum[1<=j<=M]:{ A(i, j) * Y(j) } >= B(i)

		b) se X(i) <= 0 no primal, entao:
				sum[1<=j<=M]:{ A(i, j) * Y(j) } <= B(i)

		c) se X(i) eh livre no primal, entao:
				sum[1<=j<=M]:{ A(i, j) * Y(j) } = B(i)

A reciproca eh valida!


