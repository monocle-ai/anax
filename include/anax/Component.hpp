///
/// anax
/// An open source C++ entity system.
///
/// Copyright (C) 2013-2014 Miguel Martin (miguel@miguel-martin.com)
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///

#ifndef ANAX_COMPONENT_HPP
#define ANAX_COMPONENT_HPP

#include <cstddef>
#include <vector>
#include <functional> // for reference_wrapper

#include <anax/detail/BaseComponent.hpp>
#include <anax/detail/ClassTypeId.hpp>

namespace anax
{
    /// \brief A class that follows the CRTP pattern, used to define custom components
    /// \tparam T The Component you are defining
    ///
    /// This class uses the CRTP pattern to make a unique identifier for each component
    /// class
    ///
    /// \see detail::BaseComponent
    /// If you wish to store components generically and for further documentation.
    ///
    /// \author Miguel Martin
    template <typename T>
    class Component : public detail::BaseComponent
    {
    public:

        static detail::TypeId GetTypeId()
        {
            return detail::ClassTypeId<detail::BaseComponent>::GetTypeId<T>();
        }
    };

    typedef std::vector<std::reference_wrapper<detail::BaseComponent>> ComponentArray;
}

#endif // ANAX_COMPONENT_HPP
