/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Mate
*/

#ifndef MATE_HPP_
    #define MATE_HPP_

    #include "AMaterial.hpp"

namespace RayTracer {
    class Mate : public AMaterial {
        public:
            Mate(const color &color);
            ~Mate();
    };
}

#endif /* !MATE_HPP_ */
