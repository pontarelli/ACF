#include <cstdint> // include this header for uint64_t
using namespace std;

        class CF {
		//int ***table;//  memory
		int **table;//  memory
		int   cf_size; // size of CF memory
		int   fp_size;    // 1<<f
		int   num_item;   	// number of inserted item
		int   num_access;   	// number of inserted item
		int victim_fingerprint;
		int victim_pointer;
        bool insert2(int p,int fingerprint);

		public:
		CF(int M,int f);
		virtual ~CF();
        void clear();

        bool insert(int64_t key);
        bool ddinsert(int64_t key);
        bool query(int64_t key);
        bool check(int64_t key) {return query(key);}
        bool ddquery(int64_t key);
        int get_nitem() {return num_item;}
        int get_size() {return 4*cf_size;}
        int get_numaccess() {return num_access;}

		private:
                int rot(int64_t key, int i);
                int hash(int64_t key, int i, int s);
                int RSHash(int64_t key);
                int JSHash(int64_t key);
};
