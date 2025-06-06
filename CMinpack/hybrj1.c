/* hybrj1.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "cminpack.h"
#include "cminpackP.h"

__cminpack_attr__
int __cminpack_func__(hybrj1)(__cminpack_decl_fcnder_nn__ void *p, int n, real *x, real *
	fvec, real *fjac, int ldfjac, real tol,
	real *wa, int lwa, void* user_data)
{
    /* Initialized data */

    const real factor = 100.;

    /* System generated locals */
    int fjac_dim1, fjac_offset;

    /* Local variables */
    int j, lr, mode, nfev, njev;
    real xtol;
    int maxfev, nprint;
    int info;

/*     ********** */

/*     subroutine hybrj1 */

/*     the purpose of hybrj1 is to find a zero of a system of */
/*     n nonlinear functions in n variables by a modification */
/*     of the powell hybrid method. this is done by using the */
/*     more general nonlinear equation solver hybrj. the user */
/*     must provide a subroutine which calculates the functions */
/*     and the jacobian. */

/*     the subroutine statement is */

/*       subroutine hybrj1(fcn,n,x,fvec,fjac,ldfjac,tol,info,wa,lwa) */

/*     where */

/*       fcn is the name of the user-supplied subroutine which */
/*         calculates the functions and the jacobian. fcn must */
/*         be declared in an external statement in the user */
/*         calling program, and should be written as follows. */

/*         subroutine fcn(n,x,fvec,fjac,ldfjac,iflag) */
/*         integer n,ldfjac,iflag */
/*         double precision x(n),fvec(n),fjac(ldfjac,n) */
/*         ---------- */
/*         if iflag = 1 calculate the functions at x and */
/*         return this vector in fvec. do not alter fjac. */
/*         if iflag = 2 calculate the jacobian at x and */
/*         return this matrix in fjac. do not alter fvec. */
/*         --------- */
/*         return */
/*         end */

/*         the value of iflag should not be changed by fcn unless */
/*         the user wants to terminate execution of hybrj1. */
/*         in this case set iflag to a negative integer. */

/*       n is a positive integer input variable set to the number */
/*         of functions and variables. */

/*       x is an array of length n. on input x must contain */
/*         an initial estimate of the solution vector. on output x */
/*         contains the final estimate of the solution vector. */

/*       fvec is an output array of length n which contains */
/*         the functions evaluated at the output x. */

/*       fjac is an output n by n array which contains the */
/*         orthogonal matrix q produced by the qr factorization */
/*         of the final approximate jacobian. */

/*       ldfjac is a positive integer input variable not less than n */
/*         which specifies the leading dimension of the array fjac. */

/*       tol is a nonnegative input variable. termination occurs */
/*         when the algorithm estimates that the relative error */
/*         between x and the solution is at most tol. */

/*       info is an integer output variable. if the user has */
/*         terminated execution, info is set to the (negative) */
/*         value of iflag. see description of fcn. otherwise, */
/*         info is set as follows. */

/*         info = 0   improper input parameters. */

/*         info = 1   algorithm estimates that the relative error */
/*                    between x and the solution is at most tol. */

/*         info = 2   number of calls to fcn with iflag = 1 has */
/*                    reached 100*(n+1). */

/*         info = 3   tol is too small. no further improvement in */
/*                    the approximate solution x is possible. */

/*         info = 4   iteration is not making good progress. */

/*       wa is a work array of length lwa. */

/*       lwa is a positive integer input variable not less than */
/*         (n*(n+13))/2. */

/*     subprograms called */

/*       user-supplied ...... fcn */

/*       minpack-supplied ... hybrj */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;
    fjac_dim1 = ldfjac;
    fjac_offset = 1 + fjac_dim1 * 1;
    fjac -= fjac_offset;
    --wa;

    /* Function Body */

/*     check the input parameters for errors. */

    if (n <= 0 || ldfjac < n || tol < 0. || lwa < n * (n + 13) / 2) {
        return 0;
    }

/*     call hybrj. */

    maxfev = (n + 1) * 100;
    xtol = tol;
    mode = 2;
    for (j = 1; j <= n; ++j) {
	wa[j] = 1.;
/* L10: */
    }
    nprint = 0;
    lr = n * (n + 1) / 2;
    info = __cminpack_func__(hybrj)(__cminpack_param_fcnder_nn__ p, n, &x[1], &fvec[1], &fjac[fjac_offset], ldfjac, xtol,
	    maxfev, &wa[1], mode, factor, nprint, &nfev, &njev, &wa[
	    n * 6 + 1], lr, &wa[n + 1], &wa[(n << 1) + 1], &wa[n * 3 + 1],
	     &wa[(n << 2) + 1], &wa[n * 5 + 1], user_data);
    if (info == 5) {
	info = 4;
    }
    return info;

/*     last card of subroutine hybrj1. */

} /* hybrj1_ */

