/////////////////////////////////////////////////////  
// 
//   use  c  define class like c++  vector class
// 
//   author :  lirui
//
//   history :  2012-11-16 create
// 
///  constructor destructor operator=(copy)  compare
///  assign  clear  begin  end  at rbegin rend
///  insert  push_back push_front empty size
///  pop_back  pop_front erase capacity  new delete
//   front   back reverse
//   resize  reserve
//
/////////////////////////////////////////////

#include "class.h"

#ifndef   DEFINE_C_STRUCT_USE_CPLUSPLUS_VECTOR_H
#define   DEFINE_C_STRUCT_USE_CPLUSPLUS_VECTOR_H



////////////////// fun pointer

#define   METHOD_PTR_VECTOR_copy(TYPE)                         vector_##TYPE*  (*copy)(vector_##TYPE *_this , const vector_##TYPE *_that)

#define   METHOD_PTR_VECTOR_compare(TYPE)                      long  (*compare)(const vector_##TYPE *_this , const vector_##TYPE *_that , long (*cmp)(const TYPE *_a , const TYPE *_b , size_t _size))

#define   METHOD_PTR_VECTOR_assign(TYPE)                       void  (*assign)(vector_##TYPE *_this , size_t _count , const TYPE _value)

#define   METHOD_PTR_VECTOR_assign_range(TYPE)                 void  (*assign_range)(vector_##TYPE *_this , const TYPE *_begin , const TYPE *_end)

#define   METHOD_PTR_VECTOR_clear(TYPE)                        void  (*clear)(vector_##TYPE *_this) 

#define   METHOD_PTR_VECTOR_begin(TYPE)                        TYPE*  (*begin)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_end(TYPE)                          TYPE*  (*end)(vector_##TYPE *_this) 

#define   METHOD_PTR_VECTOR_rbegin(TYPE)                       TYPE*  (*rbegin)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_rend(TYPE)                         TYPE*  (*rend)(vector_##TYPE *_this) 

#define   METHOD_PTR_VECTOR_const_begin(TYPE)                  const TYPE*  (*const_begin)(const vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_const_end(TYPE)                    const TYPE*  (*const_end)(const vector_##TYPE *_this) 

#define   METHOD_PTR_VECTOR_const_rbegin(TYPE)                 const TYPE*  (*const_rbegin)(const vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_const_rend(TYPE)                   const TYPE*  (*const_rend)(const vector_##TYPE *_this) 

#define   METHOD_PTR_VECTOR_at(TYPE)                           TYPE*    (*at)(vector_##TYPE *_this , long _pos) 

#define   METHOD_PTR_VECTOR_const_at(TYPE)                     const TYPE*    (*const_at)(const vector_##TYPE *_this , long _pos) 

#define   METHOD_PTR_VECTOR_insert(TYPE)                       void   (*insert)(vector_##TYPE *_this , TYPE *_pos , size_t _count , const TYPE *_value)

#define   METHOD_PTR_VECTOR_insert_range(TYPE)                 void   (*insert_range)(vector_##TYPE *_this , TYPE *_pos , const TYPE *_begin , const TYPE *_end)

#define   METHOD_PTR_VECTOR_erase(TYPE)                        TYPE*  (*erase)(vector_##TYPE *_this , TYPE *_pos)

#define   METHOD_PTR_VECTOR_erase_range(TYPE)                  TYPE*  (*erase_range)(vector_##TYPE *_this , TYPE *_begin , TYPE *_end)

#define   METHOD_PTR_VECTOR_push_back(TYPE)                    void  (*push_back)(vector_##TYPE *_this , const TYPE *_value)

#define   METHOD_PTR_VECTOR_push_front(TYPE)                   void  (*push_front)(vector_##TYPE *_this , const TYPE *_value)

#define   METHOD_PTR_VECTOR_pop_back(TYPE)                     void  (*pop_back)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_pop_front(TYPE)                    void  (*pop_front)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_back(TYPE)                         TYPE*  (*back)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_front(TYPE)                        TYPE*  (*front)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_empty(TYPE)                        long  (*empty)(const vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_size(TYPE)                         size_t (*size)(const vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_capacity(TYPE)                     size_t (*capacity)(const vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_reverse(TYPE)                      void  (*reverse)(vector_##TYPE *_this)

#define   METHOD_PTR_VECTOR_resize(TYPE)                       void  (*resize)(vector_##TYPE *_this , size_t _count , const TYPE *_value)

#define   METHOD_PTR_VECTOR_reserve(TYPE)                      void  (*reserve)(vector_##TYPE *_this , size_t _size)



///////////////////////////

#define   CLASS_METHOD_PTR_VECTOR(TYPE)                 \
            METHOD_PTR_VECTOR_copy(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_compare(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_assign(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_assign_range(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_clear(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_begin(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_end(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_rbegin(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_rend(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_const_begin(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_const_end(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_const_rbegin(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_const_rend(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_at(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_const_at(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_insert(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_insert_range(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_erase(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_erase_range(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_push_back(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_push_front(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_pop_back(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_pop_front(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_back(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_front(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_empty(TYPE) ;         \
			\
            METHOD_PTR_VECTOR_size(TYPE) ;            \
			\
            METHOD_PTR_VECTOR_capacity(TYPE) ;            \
			\
			METHOD_PTR_VECTOR_reverse(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_resize(TYPE) ;         \
			\
			METHOD_PTR_VECTOR_reserve(TYPE) 


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//

#define   METHOD_VECTOR_copy(TYPE)                         vector_##TYPE*  vector_##TYPE##_copy(vector_##TYPE *_this , const vector_##TYPE *_that) 

#define   METHOD_VECTOR_compare(TYPE)                      long  vector_##TYPE##_compare(const vector_##TYPE *_this , const vector_##TYPE *_that , long (*cmp)(const TYPE *_a , const TYPE *_b , size_t _size))

#define   METHOD_VECTOR_assign(TYPE)                       void  vector_##TYPE##_assign(vector_##TYPE *_this , size_t _count , TYPE _value)

#define   METHOD_VECTOR_assign_range(TYPE)                 void  vector_##TYPE##_assign_range(vector_##TYPE *_this , const TYPE *_begin , const TYPE *_end)

#define   METHOD_VECTOR_clear(TYPE)                        void  vector_##TYPE##_clear(vector_##TYPE *_this) 

#define   METHOD_VECTOR_begin(TYPE)                        TYPE*  vector_##TYPE##_begin(vector_##TYPE *_this)

#define   METHOD_VECTOR_end(TYPE)                          TYPE*  vector_##TYPE##_end(vector_##TYPE *_this) 

#define   METHOD_VECTOR_rbegin(TYPE)                       TYPE*  vector_##TYPE##_rbegin(vector_##TYPE *_this)

#define   METHOD_VECTOR_rend(TYPE)                         TYPE*  vector_##TYPE##_rend(vector_##TYPE *_this) 

#define   METHOD_VECTOR_const_begin(TYPE)                  const TYPE*  vector_##TYPE##_const_begin(const vector_##TYPE *_this)

#define   METHOD_VECTOR_const_end(TYPE)                    const TYPE*  vector_##TYPE##_const_end(const vector_##TYPE *_this) 

#define   METHOD_VECTOR_const_rbegin(TYPE)                 const TYPE*  vector_##TYPE##_const_rbegin(const vector_##TYPE *_this)

#define   METHOD_VECTOR_const_rend(TYPE)                   const TYPE*  vector_##TYPE##_const_rend(const vector_##TYPE *_this) 

#define   METHOD_VECTOR_at(TYPE)                           TYPE*    vector_##TYPE##_at(vector_##TYPE *_this , long _pos) 

#define   METHOD_VECTOR_const_at(TYPE)                     const TYPE*    vector_##TYPE##_const_at(const vector_##TYPE *_this , long _pos) 

#define   METHOD_VECTOR_insert(TYPE)                       void   vector_##TYPE##_insert(vector_##TYPE *_this , TYPE *_pos , size_t _count , TYPE _value)

#define   METHOD_VECTOR_insert_range(TYPE)                 void   vector_##TYPE##_insert_range(vector_##TYPE *_this , TYPE *_pos , const TYPE *_begin , const TYPE *_end)

#define   METHOD_VECTOR_erase(TYPE)                        TYPE*  vector_##TYPE##_erase(vector_##TYPE *_this , TYPE *_pos)

#define   METHOD_VECTOR_erase_range(TYPE)                  TYPE*  vector_##TYPE##_erase_range(vector_##TYPE *_this , TYPE *_begin , TYPE *_end)

#define   METHOD_VECTOR_push_back(TYPE)                    void  vector_##TYPE##_push_back(vector_##TYPE *_this , TYPE _value)

#define   METHOD_VECTOR_push_front(TYPE)                   void  vector_##TYPE##_push_front(vector_##TYPE *_this , TYPE _value)

#define   METHOD_VECTOR_pop_back(TYPE)                     void  vector_##TYPE##_pop_back(vector_##TYPE *_this)

#define   METHOD_VECTOR_pop_front(TYPE)                    void  vector_##TYPE##_pop_front(vector_##TYPE *_this)

#define   METHOD_VECTOR_back(TYPE)                         TYPE*  vector_##TYPE##_back(vector_##TYPE *_this)

#define   METHOD_VECTOR_front(TYPE)                        TYPE*  vector_##TYPE##_front(vector_##TYPE *_this)

#define   METHOD_VECTOR_empty(TYPE)                        long  vector_##TYPE##_empty(const vector_##TYPE *_this)

#define   METHOD_VECTOR_size(TYPE)                         size_t vector_##TYPE##_size(const vector_##TYPE *_this)

#define   METHOD_VECTOR_capacity(TYPE)                     size_t vector_##TYPE##_capacity(const vector_##TYPE *_this)

#define   METHOD_VECTOR_reverse(TYPE)                      void  vector_##TYPE##_reverse(vector_##TYPE *_this)

#define   METHOD_VECTOR_resize(TYPE)                       void  vector_##TYPE##_resize(vector_##TYPE *_this , size_t _count , TYPE _value)

#define   METHOD_VECTOR_reserve(TYPE)                      void  vector_##TYPE##_reserve(vector_##TYPE *_this , size_t _size)

/////////////////////////////////////////////////////

#define   CLASS_METHOD_VECTOR(TYPE)              \
            METHOD_VECTOR_copy(TYPE) ;             \
   		    \
            METHOD_VECTOR_compare(TYPE) ;              \
			\
			METHOD_VECTOR_assign(TYPE) ;           \
			\
            METHOD_VECTOR_assign_range(TYPE) ;             \
			\
            METHOD_VECTOR_clear(TYPE) ;             \
			\
			METHOD_VECTOR_begin(TYPE) ;          \
			\
			METHOD_VECTOR_end(TYPE)  ;         \
			\
            METHOD_VECTOR_rbegin(TYPE) ;            \
			\
            METHOD_VECTOR_rend(TYPE)  ;           \
			\
			METHOD_VECTOR_const_begin(TYPE) ;          \
			\
            METHOD_VECTOR_const_end(TYPE)  ;            \
			\
            METHOD_VECTOR_const_rbegin(TYPE) ;             \
			\
			METHOD_VECTOR_const_rend(TYPE) ;          \
			\
			METHOD_VECTOR_at(TYPE) ;          \
			\
			METHOD_VECTOR_const_at(TYPE) ;          \
			\
			METHOD_VECTOR_insert(TYPE) ;           \
			\
            METHOD_VECTOR_insert_range(TYPE) ;             \
			\
            METHOD_VECTOR_erase(TYPE) ;             \
			\
			METHOD_VECTOR_erase_range(TYPE) ;          \
			\
            METHOD_VECTOR_push_back(TYPE) ;              \
			\
            METHOD_VECTOR_push_front(TYPE) ;             \
			\
			METHOD_VECTOR_pop_back(TYPE) ;        \
			\
			METHOD_VECTOR_pop_front(TYPE) ;          \
			\
            METHOD_VECTOR_back(TYPE) ;           \
			\
            METHOD_VECTOR_front(TYPE);            \
			\
			METHOD_VECTOR_empty(TYPE);        \
			\
            METHOD_VECTOR_size(TYPE) ;            \
			\
            METHOD_VECTOR_capacity(TYPE) ;            \
			\
			METHOD_VECTOR_reverse(TYPE) ;        \
			\
			METHOD_VECTOR_resize(TYPE) ;        \
			\
			METHOD_VECTOR_reserve(TYPE) 
			
			

//
// vector
// first                last             end
// |                     |               |
// V                     V               V
// +-------------------------------------+
// |    ... data ...     |               |
// +-------------------------------------+
// |<--------size()----->|
// |<---------------capacity()---------->|
///
//CLASS(vector_##TYPE) \


#define  CLASS_VECTOR(TYPE)  \
CLASS(vector_##TYPE) \
{ \
    CLASS_METHOD_PTR_VECTOR(TYPE); \
    TYPE           *_Myfirst ; \
    TYPE           *_Mylast ;  \
    TYPE           *_Myend ;   \
} ; \
CLASS_METHOD_VECTOR(TYPE) ; \
\
vector_##TYPE*  vector_##TYPE##_copy(vector_##TYPE *_this , const vector_##TYPE *_that) \
{\
	if ((_this == NULL) || (_that == NULL)) \
		return _this ; \
	if (_this->capacity(_this) < _that->size(_that)) \
	{ \
	    if (_this->_Myfirst != NULL) \
			free(_this->_Myfirst) ; \
		_this->_Myfirst = (TYPE*) malloc(_that->size(_that) * sizeof(TYPE)) ; \
		_this->_Myend = _this->_Myfirst + _that->size(_that) ; \
	}\
    if (_that->empty(_that) == 0x00) \
	    memcpy(_this->_Myfirst , _that->_Myfirst , _that->size(_that) * sizeof(TYPE)) ; \
	_this->_Mylast = _this->_Myfirst + _that->size(_that) ; \
	return _this ; \
}\
\
long  vector_##TYPE##_compare(const vector_##TYPE *_this , const vector_##TYPE *_that , long (*cmp)(const TYPE *_a , const TYPE *_b , size_t _size)) \
{ \
    const TYPE *_iterator_1 , *_iterator_2 ; \
	long code = 0 ; \
	if ((_this == NULL) || (_that == NULL)) \
	{\
	    if (_this != NULL) \
		    return 1 ;  \
		if (_that != NULL) \
		    return -1 ; \
		return 0x00 ; \
	} \
	\
	for (_iterator_1 = _this->const_begin(_this) , _iterator_2 = _that->const_begin(_that) ; \
           (_iterator_1 < _this->const_end(_this)) && (_iterator_2 < _that->const_end(_that)) ; \
           ++_iterator_1 , ++_iterator_2) \
	{ \
	    code = cmp(_iterator_1 , _iterator_2 , sizeof(TYPE)) ; \
		if (code != 0) \
		    return code ; \
	}\
	if (_this->size(_this) > _that->size(_that)) \
	   return 1 ; \
	if (_this->size(_this) < _that->size(_that)) \
	   return -1 ; \
	return 0 ; \
} \
\
void  vector_##TYPE##_assign(vector_##TYPE *_this , size_t _count , TYPE _value) \
{ \
	if (_this == NULL) \
	    return ; \
	if (_this->capacity(_this) < _count) \
	{ \
	   if (_this->_Myfirst != NULL) \
	       free(_this->_Myfirst) ; \
	   _this->_Myfirst = (TYPE*) malloc(_count * sizeof(TYPE)) ; \
	   _this->_Myend = _this->_Myfirst + _count ; \
	} \
	\
	for (_this->_Mylast = _this->_Myfirst ; _count > 0 ; --_count , ++_this->_Mylast) \
	   memcpy(_this->_Mylast , &_value , sizeof(TYPE)) ; \
} \
\
void  vector_##TYPE##_assign_range(vector_##TYPE *_this , const TYPE *_begin , const TYPE *_end) \
{ \
    size_t _count = (_end - _begin) ; \
    if ((_this == NULL) || (_begin == NULL) || (_end == NULL) || (_begin > _end)) \
	    return ; \
	_count = (_end - _begin) ; \
	if (_this->capacity(_this) < _count) \
	{ \
	   if (_this->_Myfirst != NULL) \
	       free(_this->_Myfirst) ; \
	   _this->_Myfirst = (TYPE*) malloc(_count * sizeof(TYPE)) ; \
	   _this->_Myend = _this->_Myfirst + _count ; \
	} \
	\
    memcpy(_this->_Myfirst , _begin , _count * sizeof(TYPE)) ; \
    _this->_Mylast = _this->_Myfirst + _count ; \
}\
\
void  vector_##TYPE##_clear(vector_##TYPE *_this)  \
{ \
	if (_this == NULL) \
	    return ;  \
	_this->_Mylast = _this->_Myfirst ; \
}\
\
TYPE*  vector_##TYPE##_begin(vector_##TYPE *_this) \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return _this->_Myfirst ; \
}\
\
TYPE*  vector_##TYPE##_end(vector_##TYPE *_this)  \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return _this->_Mylast ; \
}\
\
TYPE*  vector_##TYPE##_rbegin(vector_##TYPE *_this) \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return (_this->_Mylast - 1) ; \
}\
\
TYPE*  vector_##TYPE##_rend(vector_##TYPE *_this)  \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return (_this->_Myfirst - 1) ; \
}\
\
const TYPE*  vector_##TYPE##_const_begin(const vector_##TYPE *_this) \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return _this->_Myfirst ; \
}\
\
const TYPE*  vector_##TYPE##_const_end(const vector_##TYPE *_this)   \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return _this->_Mylast ; \
}\
\
const TYPE*  vector_##TYPE##_const_rbegin(const vector_##TYPE *_this) \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return (_this->_Mylast - 1) ; \
}\
\
const TYPE*  vector_##TYPE##_const_rend(const vector_##TYPE *_this)   \
{ \
     if (_this == NULL) \
	     return NULL ; \
	 return (_this->_Myfirst - 1) ; \
}\
\
TYPE*    vector_##TYPE##_at(vector_##TYPE *_this , long _pos) \
{ \
     if ((_this == NULL) || (_pos < 0) || (_this->size(_this) <= _pos))  \
	     return NULL ; \
	 return (_this->_Myfirst + _pos) ; \
}\
\
const TYPE*    vector_##TYPE##_const_at(const vector_##TYPE *_this , long _pos)  \
{ \
     if ((_this == NULL) || (_pos < 0) || (_this->size(_this) <= _pos))  \
	     return NULL ; \
	 return (_this->_Myfirst + _pos) ; \
}\
\
void   vector_##TYPE##_insert(vector_##TYPE *_this , TYPE *_pos , size_t _count , TYPE _value) \
{ \
     size_t pos = 0 , _size = 0; \
	 TYPE *_iterator = NULL ; \
     if ((_this == NULL) || (_pos == NULL) || (_pos < _this->_Myfirst) || (_this->_Mylast < _pos))  \
	     return  ; \
	 pos = (_pos - _this->_Myfirst) ; \
	 _size = _this->size(_this) ; \
	 if (_this->capacity(_this) < (_size + _count)) \
	 { \
	    _iterator = (TYPE*) malloc(2 * (_size + _count) * sizeof(TYPE)) ; \
		_this->_Mylast = _iterator + _size + _count ; \
		_this->_Myend = _iterator + 2 * (_size + _count) ; \
		if ((_size > 0x0) &&(pos > 0)) \
    	   memcpy(_iterator , _this->_Myfirst , pos * sizeof(TYPE)) ; \
		for (_pos = _iterator + pos ; _count > 0 ; --_count , ++_pos) \
		   memcpy(_pos , &_value , sizeof(TYPE)) ; \
		if ((_size > 0x0) || (_size > pos))\
    	   memcpy(_pos , _this->_Myfirst + pos , (_size - pos) * sizeof(TYPE)) ; \
		if (_this->_Myfirst != NULL) \
		   free(_this->_Myfirst) ; \
		_this->_Myfirst = _iterator ; \
		return ; \
	 }\
	 for (_iterator = _this->rbegin(_this) ; _iterator >= _pos ; --_iterator) \
	    memcpy(_iterator + _count , _iterator , sizeof(TYPE)) ; \
	 _this->_Mylast += _count ; \
	 for (_iterator = _pos ; _count > 0 ; --_count , ++_iterator) \
	    memcpy(_iterator , &_value , sizeof(TYPE)) ; \
	 return (_this->_Myfirst + pos) ; \
}\
\
void   vector_##TYPE##_insert_range(vector_##TYPE *_this , TYPE *_pos , const TYPE *_begin , const TYPE *_end) \
{ \
     size_t pos = 0 , _size = 0 , _count = 0 ; \
	 TYPE *_iterator = NULL ; \
     if ((_this == NULL) || (_pos == NULL)  || (_pos < _this->_Myfirst) || \
	      (_this->_Mylast < _pos) || (_begin == NULL) || (_end == NULL) || (_begin >= _end))  \
	     return  ; \
	 pos = (_pos - _this->_Myfirst) ; \
	 _count = (_end - _begin) ;  \
	 _size = _this->size(_this) ; \
	 if (_this->capacity(_this) < (_size + _count)) \
	 { \
	    _iterator = (TYPE*) malloc(2 * (_size + _count) * sizeof(TYPE)) ; \
		if (_size > 0x0) \
    	   memcpy(_iterator , _this->_Myfirst , pos * sizeof(TYPE)) ; \
		memcpy(_iterator + pos , _begin , _count * sizeof(TYPE)) ; \
		if (_size > 0x0) \
    	   memcpy(_pos , _this->_Myfirst + pos , (_size - pos) * sizeof(TYPE)) ; \
		if (_this->_Myfirst != NULL) \
		   free(_this->_Myfirst) ; \
		_this->_Myfirst = _iterator ; \
		_this->_Mylast = _iterator + _size + _count ; \
		_this->_Myend = _iterator + 2 * (_size + _count) ; \
		return ; \
	 }\
	 _iterator = _this->_Mylast - 1 ; \
	 for (_iterator = _this->rbegin(_this) ; _iterator >= _pos ; --_iterator) \
	    memcpy(_iterator + _count , _iterator , sizeof(TYPE)) ; \
	 memcpy(_pos , _begin , _count * sizeof(TYPE)) ; \
     _this->_Mylast += _count ; \
	 return (_this->_Myfirst + pos) ; \
}\
\
TYPE*  vector_##TYPE##_erase(vector_##TYPE *_this , TYPE *_pos) \
{  \
	 TYPE *_iterator = _pos ; \
     if ((_this == NULL) || (_pos == NULL) || (_pos < _this->_Myfirst) || (_this->_Mylast < _pos))  \
	     return  NULL ; \
	 for ( ; (_pos + 1) != _this->end(_this) ; ++_pos) \
		memcpy(_pos , _pos + 1, sizeof(TYPE)) ; \
	 --_this->_Mylast ; \
	 return _iterator ; \
}\
\
TYPE*  vector_##TYPE##_erase_range(vector_##TYPE *_this , TYPE *_begin , TYPE *_end) \
{  \
	 TYPE *_iterator = _begin ; \
     if ((_this == NULL) || (_begin == NULL) || (_end == NULL) || (_begin > _end) || (_this->empty(_this) == 1)) \
	     return  NULL ; \
	 if (_begin < _this->begin(_this)) \
		 _begin = _this->begin(_this) ; \
	 if (_end > _this->end(_this)) \
	     _end = _this->end(_this) ; \
	 _iterator = _begin ; \
	 for ( ; _end < _this->end(_this) ; ++_begin , ++_end ) \
		memcpy(_begin , _end , sizeof(TYPE)) ; \
	 _this->_Mylast = _begin ; \
	 return _iterator ; \
}\
\
void  vector_##TYPE##_push_back(vector_##TYPE *_this , TYPE _value) \
{ \
     if (_this == NULL) \
	     return ; \
	 _this->insert(_this , _this->end(_this) , 1 , _value); \
}\
\
void  vector_##TYPE##_push_front(vector_##TYPE *_this , TYPE _value)\
{ \
     if (_this == NULL) \
	     return ; \
	 _this->insert(_this , _this->begin(_this) , 1 , _value); \
}\
\
void  vector_##TYPE##_pop_back(vector_##TYPE *_this)  \
{ \
     if ((_this == NULL) || (_this->empty(_this) == 1)) \
	     return ; \
	 --_this->_Mylast ; \
}\
\
void  vector_##TYPE##_pop_front(vector_##TYPE *_this) \
{ \
     TYPE *_iterator ;\
     if ((_this == NULL) || (_this->empty(_this) == 1)) \
	     return ; \
	 for (_iterator = _this->begin(_this) ; (_iterator + 1) < _this->end(_this) ; ++_iterator) \
	     memcpy(_iterator , _iterator + 1 , sizeof(TYPE)) ; \
	 --_this->_Mylast ; \
}\
\
TYPE*  vector_##TYPE##_back(vector_##TYPE *_this)  \
{ \
	return (_this->end(_this) - 1) ; \
}\
\
TYPE*  vector_##TYPE##_front(vector_##TYPE *_this)\
{ \
    return _this->begin(_this) ; \
}\
\
long  vector_##TYPE##_empty(const vector_##TYPE *_this) \
{ \
   if (_this == NULL) \
       return 1 ; \
   return (long) (_this->_Mylast == _this->_Myfirst ? 1 : 0) ; \
} \
\
size_t vector_##TYPE##_size(const vector_##TYPE *_this) \
{ \
   if (_this == NULL) \
       return 0 ; \
   return (size_t) (_this->_Mylast - _this->_Myfirst) ; \
} \
\
size_t vector_##TYPE##_capacity(const vector_##TYPE *_this) \
{ \
   if (_this == NULL) \
       return 0 ; \
   return (size_t) (_this->_Myend - _this->_Myfirst) ; \
} \
\
void  vector_##TYPE##_reverse(vector_##TYPE *_this) \
{ \
   TYPE *_begin = NULL , *_end = NULL  , *_value = NULL ; \
   if ((_this == NULL) || (_this->empty(_this) == 1)) \
       return  ; \
   _begin = _this->begin(_this) ; \
   _end   = _this->rbegin(_this) ; \
   _value = (TYPE*) malloc(sizeof(TYPE)) ; \
   for ( ; _begin < _end ; ++_begin , --_end) \
   { \
      memcpy(_value , _begin , sizeof(TYPE)) ; \
	  memcpy(_begin , _end , sizeof(TYPE)) ; \
	  memcpy(_end , _value , sizeof(TYPE)) ; \
   }\
   free(_value) ;\
} \
\
void  vector_##TYPE##_resize(vector_##TYPE *_this , size_t _count , TYPE _value) \
{\
   size_t  _size = 0 ; \
   if ((_this == NULL) || (_count <= 0)) \
       return ; \
   _size = _this->size(_this) ; \
   if (_size >= _count) \
       _this->_Mylast = _this->_Myfirst + _count ; \
   else \
      _this->insert(_this , _this->end(_this) , (_count - _size) , _value) ; \
}\
\
void  vector_##TYPE##_reserve(vector_##TYPE *_this , size_t _size) \
{ \
   TYPE *iterator = NULL ; \
   size_t  sz = 0 ; \
   if ((_this == NULL) || (_size <= 0))\
       return ; \
   sz = _this->size(_this) ; \
   iterator = (TYPE*) malloc(_size * sizeof(TYPE)) ; \
   _this->_Myend = iterator + _size ; \
   if (sz >= _size) \
	   sz = _size ; \
   if (sz > 0) \
	  memcpy(iterator , _this->_Myfirst , sz * sizeof(TYPE)) ; \
    if (_this->_Myfirst != NULL) \
	   free(_this->_Myfirst) ;\
	_this->_Myfirst = iterator ; \
	_this->_Mylast = iterator + sz ; \
}\
\
\
CONSTRUCT(vector_##TYPE) \
{\
	_this->_Myfirst = NULL ; \
	_this->_Mylast = NULL ;  \
	_this->_Myend  = NULL ; \
\
	SET_METHOD(copy , vector_##TYPE##_copy) ; \
	SET_METHOD(compare , vector_##TYPE##_compare) ; \
	SET_METHOD(assign , vector_##TYPE##_assign) ; \
	SET_METHOD(assign_range , vector_##TYPE##_assign_range) ; \
	SET_METHOD(clear , vector_##TYPE##_clear) ; \
	SET_METHOD(begin , vector_##TYPE##_begin) ; \
	SET_METHOD(end , vector_##TYPE##_end) ; \
	SET_METHOD(rbegin , vector_##TYPE##_rbegin) ; \
\
	SET_METHOD(rend , vector_##TYPE##_rend) ; \
	SET_METHOD(const_begin , vector_##TYPE##_const_begin) ; \
	SET_METHOD(const_end , vector_##TYPE##_const_end) ; \
	SET_METHOD(const_rbegin , vector_##TYPE##_const_rbegin) ; \
	SET_METHOD(const_rend , vector_##TYPE##_const_rend) ; \
	SET_METHOD(at , vector_##TYPE##_at) ; \
	SET_METHOD(const_at , vector_##TYPE##_const_at) ; \
	SET_METHOD(insert , vector_##TYPE##_insert) ; \
\
	SET_METHOD(insert_range , vector_##TYPE##_insert_range) ; \
	SET_METHOD(erase , vector_##TYPE##_erase) ; \
	SET_METHOD(erase_range , vector_##TYPE##_erase_range) ; \
	SET_METHOD(push_back , vector_##TYPE##_push_back) ; \
	SET_METHOD(push_front , vector_##TYPE##_push_front);  \
	SET_METHOD(pop_back , vector_##TYPE##_pop_back) ; \
	SET_METHOD(pop_front , vector_##TYPE##_pop_front) ; \
	SET_METHOD(back , vector_##TYPE##_back) ; \
\
	SET_METHOD(front , vector_##TYPE##_front) ; \
	SET_METHOD(empty , vector_##TYPE##_empty) ; \
	SET_METHOD(size , vector_##TYPE##_size) ; \
	SET_METHOD(capacity , vector_##TYPE##_capacity) ; \
	SET_METHOD(reverse , vector_##TYPE##_reverse) ; \
	SET_METHOD(resize , vector_##TYPE##_resize) ; \
	SET_METHOD(reserve , vector_##TYPE##_reserve) ; \
}\
\
DESTRUCT(vector_##TYPE)\
{\
	if (_this->_Myfirst != NULL) \
	    free(_this->_Myfirst) ; \
	_this->_Myfirst = _this->_Mylast = _this->_Myend = NULL ; \
}
 

#define  vector(type)    vector_##type

#define  VECTOR(TYPE , VALUE)   vector(TYPE) VALUE ; \
                                vector_##TYPE##_Construct((vector_##TYPE*)&VALUE)
								
#define  vector_New(type)       New(vector_##type) 

#endif

