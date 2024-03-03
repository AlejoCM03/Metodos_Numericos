import math

def funcion(x):
    #return math.exp(-x)-x
    #return math.exp(x)-math.log(3)-x
    return math.log(10)-2*pow(x,2)+math.sqrt(x)

def biseccion(xi, xu, errorMin, maxIter):
    xrAnt = 0.0
    xr = 0.0
    error = 0.0
    i = 0

    if funcion(xi) * funcion(xu) > 0:
        print("No existe raiz en ese intervalo")
    else:
        while True:
            i += 1
            xrAnt = xr
            xr = (xi + xu)/2
            error = abs(((xr - xrAnt)/xr)*100)

            if funcion(xi)*funcion(xr)<0:
                xu = xr
            elif funcion(xi)*funcion(xr)>0:
                xi = xr
            else:
                error = 0
                i = maxIter

            print("Valor xi = ",xi)
            print("Valor xr = ",xr)
            print("Valor xu = ",xu)
            print("\n\t\tNumero de iteracion: ",i)
            print("\t\tError = ",error)

            if i >= maxIter or error <= errorMin:
                break
        print("\n\nValor de la raiz: %.4lf" % xr)

def main():
    xi = float(input("Dame el limite inferior del intervalo: "))
    xu = float(input("Dame el limite superior del intervalo: "))
    maxIter = int(input("Especifica el numero de iteraciones: "))
    errorMin = float(input("Especifica el error minimo del calculo: "))

    biseccion(xi, xu, errorMin, maxIter)

if __name__ == "__main__":
    main()
                        
                     

