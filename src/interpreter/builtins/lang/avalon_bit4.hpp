/*
 *  This file is part of the Avalon programming language
 * 
 *  Copyright (c) 4018 Ntwali Bashige Toussaint
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef AVALON_INTERPRETER_BUILTINS_LANG_BIT4_HPP_
#define AVALON_INTERPRETER_BUILTINS_LANG_BIT4_HPP_

#include <memory>
#include <vector>

/* AST */
#include "representer/ast/decl/type.hpp"
#include "representer/ast/expr/expr.hpp"


namespace avalon {
    /**
     * bit4_and
     * computes the bitwise and of two bit expressions
     */
    std::shared_ptr<expr> bit4_and(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_or
     * computes the bitwise or of two bit expressions
     */
    std::shared_ptr<expr> bit4_or(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_xor
     * computes the bitwise xor of two bit expressions
     */
    std::shared_ptr<expr> bit4_xor(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_not
     * computes the bitwise not of a single bit expressions
     */
    std::shared_ptr<expr> bit4_not(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_cast
     * returns an expression cast that represented the bit with a type specified by ret_instance
     */
    std::shared_ptr<expr> bit4_cast(std::vector<std::shared_ptr<expr> >& arguments, type_instance& ret_instance);

    /**
     * bit4_string
     * returns a bit representation of a string
     */
    std::shared_ptr<expr> bit4_string(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_eq
     * returns a bit indicating whether its arguments are equal
     */
    std::shared_ptr<expr> bit4_eq(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_ne
     * returns a bit indicating whether its arguments are not equal
     */
    std::shared_ptr<expr> bit4_ne(std::vector<std::shared_ptr<expr> >& arguments);

    /**
     * bit4_refitem
     * returns the effective index where to find the requested bit
     */
    std::shared_ptr<expr> bit4_refitem(std::vector<std::shared_ptr<expr> >& arguments);
}

#endif
