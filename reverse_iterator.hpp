#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iostream>

namespace ft{
    template <class Iter>
    class reverse_iterator{
        public:
            typedef Iter                                                            iterator_type;
            typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
            typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
            typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
            typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
            typedef typename std::iterator_traits<iterator_type>::reference         reference;
        private:
        public:
            iterator_type it;
            reverse_iterator(): it()
            {
            }

            explicit reverse_iterator (iterator_type it)
            {
                this->it = it;
            }

            reverse_iterator(reverse_iterator const & src)
            {
                this->it = src.it;
            }

            template <class Iterator>
            reverse_iterator (const reverse_iterator<Iterator>& rev_it) : it(rev_it.base())
            {
                
            }

            ~reverse_iterator()
            {
                
            }

             reverse_iterator    &operator=(iterator_type  const & src)
             {
                 this->it = src.base();
         
                 return(*this);
             }

            iterator_type base() const
            {
                return it;
            }

             reference    operator*() const
             {
                 Iter it1 = it;
                 it1--;
                 return *it1;
             }
             
             pointer operator->() const
             {
                 return &(operator*());
             }
             
             reverse_iterator& operator++()
             {
                 this->it--;
                 return (*this);
             }
             
             reverse_iterator operator++(int) 
             {
                 reverse_iterator temp = *this;
                 ++(*this);
                 return temp;
             }
             
            reverse_iterator operator+ (difference_type n) const
            {
                std::cout << "===>\n";
                return(reverse_iterator(it - n));
            }

            reverse_iterator& operator+= (difference_type n)
            {
                this->it -= n;
                return(*this);
            }

             reverse_iterator operator- (difference_type n) const
             {
                 return(reverse_iterator(this->it + n));
             }
             reverse_iterator& operator--()
             {
                 this->it++;
                 return (*this);
             }
             reverse_iterator operator--(int) 
             {
                 reverse_iterator temp = *this;
                 --(*this);
                 return temp;
             }
             reverse_iterator& operator-= (difference_type n)
             {
                 this->it += n;
                 return(*this);
             }  

            reference operator[] (difference_type n) const
            {
                return *(this->it + n);
            }


    };
     template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() != rhs.base())
                        return true;
                    else
                        return false;
                   }

    template <class Iterator>
  bool operator== (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() == rhs.base())
                        return (true);
                    else
                        return false;
                   }

    template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
                   {
                    if (lhs.base() > rhs.base())
                        return true;
                    else
                        return false;
                   }

     template <class Iterator>
     bool operator> (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() < rhs.base())
                         return true;
                     else
                         return false;
                    }
    
     template <class Iterator>
     bool operator>= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() <= rhs.base())
                         return true;
                     else
                         return false;
                    }

     template <class Iterator>
     bool operator<= (const reverse_iterator<Iterator>& lhs,
                    const reverse_iterator<Iterator>& rhs)
                    {
                     if (lhs.base() >= rhs.base())
                         return true;
                     else
                         return false;
                    }

    template <class Iterator>
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
             {
                return (rev_it + n);
             }

    template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
};

#endif