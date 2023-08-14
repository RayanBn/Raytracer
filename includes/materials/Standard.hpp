/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Standard
*/

#ifndef STANDARD_HPP_
    #define STANDARD_HPP_

    #include "AMaterial.hpp"

namespace RayTracer {
    class Standard : public AMaterial {
        public:
            Standard(const color &color);
            ~Standard();
    };
}

#endif /* !STANDARD_HPP_ */
