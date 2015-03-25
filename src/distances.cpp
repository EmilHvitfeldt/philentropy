#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

//' @export
// [[Rcpp::export]]
double euclidean(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist  = 0;
        double diff  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff = P[i] - Q[i];
                dist = dist + (diff * diff);
                        
        }
        
        return sqrt(dist);
}


//' @export
// [[Rcpp::export]]
double manhattan(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist  = 0;
        double diff  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff = fabs(P[i] - Q[i]);
                dist = dist + diff;
                        
        }
        
        return dist;
}



//' @export
// [[Rcpp::export]]
double minkowski(NumericVector P, NumericVector Q, double n){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist  = 0.0;
        double diff  = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
       
        
        for(int i = 0; i < P_len; i++){
                
                diff = pow(fabs(P[i] - Q[i]), n);
                dist = dist + diff;
                        
        }
        
        return pow(dist ,  1.0/n);
}


//' @export
// [[Rcpp::export]]
double chebyshev(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist  = 0;
        double diff  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
     
        
        for(int i = 0; i < P_len; i++){
                
                diff = fabs(P[i] - Q[i]);
                
                if (diff > dist)
                     dist = diff;
                        
        }
        
        return dist;
}


//' @export
// [[Rcpp::export]]
double sorensen(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist1 = 0;
        double dist2 = 0;
        double diff  = 0;
        double sum   = 0;
        
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff = fabs(P[i] - Q[i]);
                sum = P[i] + Q[i];
                
                dist1 = dist1 + diff;
                dist2 = dist2 + sum;
                
        }
        
        
        return dist1/dist2;
}



//' @export
// [[Rcpp::export]]
double gower(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double diff  = 0;
        double dist  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff = fabs(P[i] - Q[i]);
                dist = dist + diff;
                
        }
        
        return ((1.0/P_len) * dist);
        
}



//' @export
// [[Rcpp::export]]
double soergel(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double diff       = 0;
        double dist1      = 0;
        double dist2      = 0;
        double max_point  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff      = fabs(P[i] - Q[i]);
                
                if (P[i] >= Q[i]){
                        
                        max_point = P[i];
                        
                } else {
                        
                        max_point = Q[i];
                }
               
                dist1 = dist1 + diff;
                dist2 = dist2 + max_point;
                
        }
        
        return dist1/dist2;
        
}


//' @export
// [[Rcpp::export]]
double kulczynski_d(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double diff       = 0;
        double dist1      = 0;
        double dist2      = 0;
        double min_point  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff      = fabs(P[i] - Q[i]);
                
                if (P[i] <= Q[i]){
                        
                        min_point = P[i];
                        
                } else {
                        
                        min_point = Q[i];
                }
               
                dist1 = dist1 + diff;
                dist2 = dist2 + min_point;
                
        }
        
        return dist1/dist2;
        
}


//' @export
// [[Rcpp::export]]
double canberra(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist = 0;
        double diff  = 0;
        double sum   = 0;
        
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff = fabs(P[i] - Q[i]);
                sum  = P[i] + Q[i];
                dist = dist + (diff / sum);
                
        }
        
        
        return dist;
}


//' @export
// [[Rcpp::export]]
double lorentzian(NumericVector P, NumericVector Q){
        
        int    P_len = P.size();
        int    Q_len = Q.size();
        double dist  = 0;
        double diff  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff = fabs(P[i] - Q[i]);
                
                dist = dist + (log(1.0 + diff));
                        
        }
        
        return dist;
}


//' @export
// [[Rcpp::export]]
double intersection_dist(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0;
        double min_point  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                                
                if (P[i] <= Q[i]){
                        
                        min_point = P[i];
                        
                } else {
                        
                        min_point = Q[i];
                }
               
                dist = dist + min_point;
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double wave_hedges(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double diff       = 0;
        double dist       = 0;
        double max_point  = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff      = fabs(P[i] - Q[i]);
                
                if (P[i] >= Q[i]){
                        
                        max_point = P[i];
                        
                } else {
                        
                        max_point = Q[i];
                }
               
                dist = dist + (diff / max_point);
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double czekanowski(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double diff       = 0;
        double sum        = 0;
        double dist1      = 0;
        double dist2      = 0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                diff  = fabs(P[i] - Q[i]);
                sum   = P[i] + Q[i];
                
               
                dist1 = dist1 + diff;
                dist2 = dist2 + sum;
                
        }
        
        return dist1 / dist2;
        
}



//' @export
// [[Rcpp::export]]
double motyka(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double sum        = 0.0;
        double dist1      = 0.0;
        double dist2      = 0.0;
        double min_point  = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        
        for(int i = 0; i < P_len; i++){
                
                sum      = P[i] + Q[i];
                
                if (P[i] <= Q[i]){
                        
                        min_point = P[i];
                        
                } else {
                        
                        min_point = Q[i];
                }
               
                dist1 = dist1 + min_point;
                dist2 = dist2 + sum;
                
        }
        
        return (1.0 - (dist1 / dist2));
        
}


//' @export
// [[Rcpp::export]]
double tanimoto(NumericVector P, NumericVector Q){
        
        // Soergel = Tanimoto
        return soergel(P, Q);
}


//' @export
// [[Rcpp::export]]
double ruzicka(NumericVector P, NumericVector Q){
        
        // Ruzicka = 1 - Tanimoto = 1 - Soergel
        return (1.0 - soergel(P, Q));
}


//' @export
// [[Rcpp::export]]
double inner_product(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + (P[i] * Q[i]);
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double harmonic_mean_dist(NumericVector P, NumericVector Q){
        
        int    P_len     = P.size();
        int    Q_len     = Q.size();
        double prod      = 0.0;
        double sum       = 0.0;
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                prod = P[i] * Q[i];
                sum  = P[i] + Q[i];
                
                dist = dist + (prod / sum);
                
        }
        
        return (2.0 * dist);
        
}


//' @export
// [[Rcpp::export]]
double cosine_dist(NumericVector P, NumericVector Q){
        
        int    P_len     = P.size();
        int    Q_len     = Q.size();
        double prod      = 0.0;
        double p_square  = 0.0;
        double q_square  = 0.0;
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                prod = P[i] * Q[i];
                
                p_square  = p_square + pow(P[i], 2);
                q_square  = q_square + pow(Q[i], 2);
                
                dist = dist + prod;
                
        }
        
        return (dist / (sqrt(p_square) * sqrt(q_square)));
        
}


//' @export
// [[Rcpp::export]]
double kumar_hassebrook(NumericVector P, NumericVector Q){
        
        int    P_len     = P.size();
        int    Q_len     = Q.size();
        double prod      = 0.0;
        double p_square  = 0.0;
        double q_square  = 0.0;
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                prod = P[i] * Q[i];
                
                p_square  = p_square + pow(P[i], 2);
                q_square  = q_square + pow(Q[i], 2);
                
                dist = dist + prod;
                
        }
        
        return (dist / (p_square + q_square - dist));
        
}


//' @export
// [[Rcpp::export]]
double jaccard(NumericVector P, NumericVector Q){
        
        return (1.0 - kumar_hassebrook(P,Q));
        
}


//' @export
// [[Rcpp::export]]
double dice_dist(NumericVector P, NumericVector Q){
        
        int    P_len       = P.size();
        int    Q_len       = Q.size();
        double diff_square = 0.0;
        double p_square    = 0.0;
        double q_square    = 0.0;
        double dist        = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                diff_square = pow((P[i] - Q[i]), 2);
                
                p_square    = p_square + pow(P[i], 2);
                q_square    = q_square + pow(Q[i], 2);
                
                dist = dist + diff_square;
                
        }
        
        return (dist / (p_square + q_square));
        
}


//' @export
// [[Rcpp::export]]
double fidelity(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + sqrt(P[i] * Q[i]);
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double bhattacharyya(NumericVector P, NumericVector Q){
        
        
        return -log(fidelity(P,Q));
}


//' @export
// [[Rcpp::export]]
double hellinger(NumericVector P, NumericVector Q){
        
        
        return 2.0 * sqrt( 1.0 - fidelity(P,Q));
}

//' @export
// [[Rcpp::export]]
double matusita(NumericVector P, NumericVector Q){
        
        
        return sqrt( 2.0 - ( 2.0 * fidelity(P,Q)));
}

//' @export
// [[Rcpp::export]]
double squared_chord(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + pow(sqrt(P[i]) - sqrt(Q[i]), 2);
                
        }
        
        return dist;
        
}



//' @export
// [[Rcpp::export]]
double squared_euclidean(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + pow(P[i] - Q[i], 2);
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double pearson_chi_sq(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + (pow(P[i] - Q[i], 2) / Q[i]);
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double neyman_chi_sq(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + (pow(P[i] - Q[i], 2) / P[i]);
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double squared_chi_sq(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + (pow(P[i] - Q[i], 2) / (P[i] + Q[i]));
                
        }
        
        return dist;
        
}


//' @export
// [[Rcpp::export]]
double prob_symm_chi_sq(NumericVector P, NumericVector Q){
        
        return (2.0 * squared_chi_sq(P,Q));
        
}




//' @export
// [[Rcpp::export]]
double divergence_sq(NumericVector P, NumericVector Q){
        
        int    P_len      = P.size();
        int    Q_len      = Q.size();
        double dist      = 0.0;
        
        if (P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        for(int i = 0; i < P_len; i++){
                
                dist = dist + (pow(P[i] - Q[i], 2) / pow(P[i] + Q[i], 2));
                
        }
        
        return 2.0 * dist;
        
}













